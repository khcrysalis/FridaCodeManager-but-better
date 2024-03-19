import Foundation
import UIKit

func build(_ ProjectInfo: Project, _ SDK: String,_ erase: Bool) -> Int {
    let RootPath = "/var/jb"
    let PayloadPath = "\(ProjectInfo.ProjectPath)/Payload"
    let AppPath = "\(PayloadPath)/\(ProjectInfo.Executable).app"
    let Resources = "\(ProjectInfo.ProjectPath)/Resources"
    let SDKPath = "\(RootPath)/opt/theos/sdks/\(ProjectInfo.SDK)"
    let ClangPath = "\(ProjectInfo.ProjectPath)/clang"
    let ClangBridge = "\(ProjectInfo.ProjectPath)/bridge.h"
    let SwiftFiles = (FindFiles(ProjectInfo.ProjectPath, ".swift") ?? "")
    let MFiles = (findObjCFilesStack(ProjectInfo.ProjectPath) ?? [""])
    let Extension: String = load("\(ProjectInfo.ProjectPath)/extension.txt")
    let Object: ext = api(Extension,ProjectInfo)
    //compiler setup
    var EXEC = ""
    if SwiftFiles != "" {
        if !fe(ClangBridge) {
            EXEC += "swiftc -sdk '\(SDKPath)' \(SwiftFiles) -o '\(AppPath)/\(ProjectInfo.Executable)' -parse-as-library -suppress-warnings \(Object.flag) -target arm64-apple-ios\(ProjectInfo.TG)"
        } else {
            if MFiles != [] {
                for mFile in MFiles {
                EXEC += "clang -w -isysroot '\(SDKPath)' -framework UIKit -framework Foundation -target arm64-apple-ios\(ProjectInfo.TG) -c \(ProjectInfo.ProjectPath)/\(mFile) -o '\(ProjectInfo.ProjectPath)/clang/\(UUID()).o'; "
                }
                EXEC += "swiftc -sdk '\(SDKPath)' \(SwiftFiles) clang/*.o -o '\(AppPath)/\(ProjectInfo.Executable)' -parse-as-library -import-objc-header '\(ClangBridge)' -suppress-warnings -target arm64-apple-ios\(ProjectInfo.TG) \(Object.flag)"
            } else {
            EXEC += "swiftc -sdk '\(SDKPath)' \(SwiftFiles) -o '\(AppPath)/\(ProjectInfo.Executable)' -parse-as-library -import-objc-header '\(ClangBridge)' -suppress-warnings -target arm64-apple-ios\(ProjectInfo.TG) \(Object.flag)"
            }
        }
    } else if MFiles != [""] {
        EXEC += "clang -w -isysroot '\(SDKPath)' \(MFiles.joined(separator: " ")) -framework UIKit -framework Foundation -target arm64-apple-ios\(ProjectInfo.TG) -o '\(AppPath)/\(ProjectInfo.Executable)'"
    }
    let LDIDEXEC = "ldid -S'\(ProjectInfo.ProjectPath)/entitlements.plist' '\(AppPath)/\(ProjectInfo.Executable)'"
    var CLEANEXEC = ""
    if PayloadPath != "" {
        CLEANEXEC = "rm -rf '\(ClangPath)'; rm -rf '\(PayloadPath)'"
    }
    let RMEXEC = "rm '\(ProjectInfo.ProjectPath)/ts.ipa'"
    let CDEXEC = "cd '\(ProjectInfo.ProjectPath)'"
    let ZIPEXEC = "zip -r9q ./ts.ipa ./Payload"
    let INSTALL = "\(RootPath)/usr/bin/tshelper install '\(ProjectInfo.ProjectPath)/ts.ipa'"
    shell("\(CDEXEC) && \(Object.before)")
    //compiler start
    print("FridaCodeManager 1.0.1\n \n+++++++++++++++++++++++++++\nApp Name: \(ProjectInfo.Executable)\nBundleID: \(ProjectInfo.BundleID)\n+++++++++++++++++++++++++++\n ")
    cfolder(atPath: PayloadPath)
    cfolder(atPath: AppPath)
    cfolder(atPath: ClangPath)
    try? copyc(from: Resources, to: AppPath)
    print("+++++ compiler-stage ++++++")
    if shell("\(CDEXEC) && \(EXEC)") != 0 {
        print("+++++++++++++++++++++++++++\n \n+++++++++ error +++++++++++\ncompiling \(ProjectInfo.Executable) failed\n+++++++++++++++++++++++++++")
        shell(CLEANEXEC)
        return 1
    }
    print("+++++++++++++++++++++++++++\n \n+++++ install-stage +++++++")
    shell(LDIDEXEC)
    shell("\(CDEXEC) && \(ZIPEXEC)")
    shell(INSTALL, uid: 0)
    shell(CLEANEXEC)
    print("+++++++++++++++++++++++++++\n \n++++++++++ done +++++++++++")
    if erase == true {
        shell(RMEXEC)
        shell("killall '\(ProjectInfo.Executable)' > /dev/null 2>&1")
        OpenApp(ProjectInfo.BundleID)
    }
    shell("\(CDEXEC) && \(Object.after)")
    return 0
}

func OpenApp(_ BundleID: String) {
    guard let obj = objc_getClass("LSApplicationWorkspace") as? NSObject else { return }
    let workspace = obj.perform(Selector(("defaultWorkspace")))?.takeUnretainedValue() as? NSObject
    workspace?.perform(Selector(("openApplicationWithBundleID:")), with: BundleID)
}

func copyf(sourcePath: String, destinationPath: String) {
    let fileManager = FileManager.default
    
    do {
        try! fileManager.copyItem(atPath: sourcePath, toPath: destinationPath)
    }
}

func FindFiles(_ ProjectPath: String, _ suffix: String) -> String? {
    do {
        var Files: [String] = []
        for File in try FileManager.default.subpathsOfDirectory(atPath: ProjectPath).filter({$0.hasSuffix(suffix)}) {
            Files.append("'\(File)'")
        }
        return Files.joined(separator: " ")
    } catch {
        return nil
    }
}

func findObjCFilesStack(_ projectPath: String) -> [String]? {
    let fileExtensions = [".m", ".c", ".mm", ".cpp"]
    
    do {
        var objCFiles: [String] = []
        
        for fileExtension in fileExtensions {
            let files = try FileManager.default.subpathsOfDirectory(atPath: projectPath)
                .filter { $0.hasSuffix(fileExtension) }
                .map { "'\($0)'" }
            
            objCFiles.append(contentsOf: files)
        }
        
        return objCFiles
    } catch {
        return nil
    }
}

func fe(_ path: String) -> Bool {
    return FileManager.default.fileExists(atPath: path)
}