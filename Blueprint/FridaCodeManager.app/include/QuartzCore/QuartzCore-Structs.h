// This header file should no longer be used, and exists for compatibility reasons only.
// Instead, directly import the below headers as needed.
// The structs defined in this file should not be considered stable.
// Consider using the Objective-C objects that generally wrap these structs.
#import <QuartzCore/CAFunctions.h>
#import <QuartzCore/CARenderValue.h>


typedef struct {
	int x;
} XXStruct_RiyHGD;

typedef struct Atomic {
	XXStruct_RiyHGD _v;
} Atomic;

typedef struct Object {
	/*function-pointer*/ void** _field1;
	Atomic _field2;
} Object;

typedef struct Timing Timing;

typedef struct Vector Vector;

typedef struct Animation {
	/*function-pointer*/ void** _field1;
	Atomic _field2;
	float _field3;
	Timing* _field4;
	Vector* _field5;
	void* _field6;
	unsigned _field7;
	unsigned _field8;
} Animation;

typedef struct _CAAttrList* CAAttrListRef;

typedef struct Proxy {
	/*function-pointer*/ void** _field1;
	Atomic _field2;
	unsigned long long _field3;
} Proxy;

typedef struct Mutex {
	pthread_t _m;
} Mutex;

typedef struct Shmem Shmem;
typedef struct Commit Commit;
typedef struct CGColorSpace* CGColorSpaceRef;

@class CAContext, CALayer;
typedef struct Context {
	unsigned _field1;
	struct Context* _field2;
	Mutex _field3;
	CAContext* _field4;
	unsigned _field5;
	unsigned _field6;
	CALayer* _field7;
	struct Context* _field8;
	CGColorSpaceRef _field9;
	CFDictionaryRef _field10;
	unsigned _field11;
	unsigned _field12;
	CFMachPortRef _field13;
	CFRunLoopSourceRef _field14;
	Shmem* _field15;
	Shmem* _field16;
	float _field17;
	Commit* _field18;
	unsigned _field19 : 1;
	unsigned _field20 : 1;
	unsigned _field21 : 1;
} Context;

typedef struct LayerExt LayerExt;

/*
template<>
struct TypedArray<CA::Render::Layer>;

template<>
struct TypedArray<CA::Render::Animation>;
*/


typedef struct Layer {
	/*function-pointer*/ void** _field1;
	Atomic _field2;
	unsigned _field3;
	LayerExt* _field4;
	Handle* _field5;
	Object* _field6;
	CGPoint _field7;
	CGSize _field8;
	// TypedArray<CA::Render::Layer>* _field9
	void* _field9;
	// TypedArray<CA::Render::Animation>* _field10;
	void* _field10;
} Layer;

typedef struct Shared Shared;

typedef struct SpinLock {
	XXStruct_RiyHGD _l;
} SpinLock;

typedef struct Level Level;

typedef struct Command Command;

typedef struct Deleted Deleted;

typedef struct Transaction {
	Shared* _field1;
	unsigned _field2;
	// HashTable<CALayer*,uintptr_t*>* _field3;
	void* _field3;
	SpinLock* _field4;
	unsigned _field5;
	Level* _field6;
	Command* _field7;
	Deleted* _field8;
	// List<const void*>* _field9;
	void* _field9;
	Context* _field10;
	// HashTable<CALayer*,CALayer*>* _field11;
	void* _field11;
	CFRunLoopRef _field12;
	CFRunLoopObserverRef _field13;
	unsigned _field14 : 1;
} Transaction;

typedef struct _CALayerState* CALayerStateRef;

typedef struct _CALayerAnimation* CALayerAnimationRef;

@class CALayerArray;

typedef struct _CALayerArrayIvars {
	CALayer** layers;
	unsigned count;
	unsigned capacity;
	unsigned long mutations;
	BOOL retained;
} CALayerArrayIvars;

typedef struct {
	unsigned long _field1;
	id* _field2;
	unsigned long* _field3;
	unsigned long _field4[5];
} XXStruct_kFm5bA;

typedef struct CAMediaTimingFunctionPrivate {
	float _field1[2];
	float _field2[2];
} CAMediaTimingFunctionPrivate;

typedef struct _EAGLNativeWindowObject {
	int version;
	/*function-pointer*/ void* attach;
	/*function-pointer*/ void* detach;
	/*function-pointer*/ void* begin;
	/*function-pointer*/ void* swap;
	/*function-pointer*/ void* collect;
} EAGLNativeWindowObject;

typedef struct EAGLNativeWindowCallbacksRec {
	void* callback_data;
	/*function-pointer*/ void* create_buffer;
	/*function-pointer*/ void* destroy_buffer;
} EAGLNativeWindowCallbacksRec;

typedef struct x_list_struct x_list_struct;

typedef struct _CAImageQueue* CAImageQueueRef;

@class CAEAGLLayer;
typedef struct _CAEAGLNativeWindow {
	EAGLNativeWindowObject _field1;
	EAGLNativeWindowCallbacksRec _field2;
	x_list_struct* _field3;
	Atomic _field4;
	SpinLock _field5;
	CAImageQueueRef _field6;
	CAEAGLLayer* _field7;
	x_list_struct* _field8;
	unsigned _field9;
	IOSurfaceRef _field10;
	unsigned _field11 : 1;
	unsigned _field12 : 1;
} CAEAGLNativeWindow;

typedef struct Display {
	/*function-pointer*/ void** _field1;
	id _field2;
	CFStringRef _field3;
	CFStringRef _field4;
} Display;

typedef struct Condition {
	pthread_cond_t _field1;
} Condition;

typedef struct _opaque_pthread_t opaque_pthread_t;

typedef struct DisplayLink {
	/*function-pointer*/ void** _field1;
	Display* _field2;
	void* _field3;
	SEL _field4;
	void* _field5;
	int _field6;
	Mutex _field7;
	Condition _field8;
	opaque_pthread_t* _field9;
	id _field10;
	CFRunLoopRef _field11;
	// List<const __CFString*>* _field12;
	void* _field12;
	unsigned long long _field13;
	unsigned long long _field14;
	unsigned _field15 : 1;
} DisplayLink;

typedef struct PendingOperation PendingOperation;

typedef struct Shape Shape;

typedef struct _CARenderOGLContext* CARenderOGLContextRef;

typedef struct Server {
	/*function-pointer*/ void** _field1;
	SpinLock _field2;
	Display* _field3;
	CFStringRef _field4;
	Mutex _field5;
	Condition _field6;
	unsigned _field7;
	Context** _field8;
	unsigned _field9;
	unsigned _field10;
	SpinLock _field11;
	PendingOperation* _field12;
	Context* _field13;
	Context* _field14;
	unsigned _field15;
	Shape* _field16;
	unsigned _field17;
	CARenderOGLContextRef _field18;
	double _field19;
	unsigned _field20 : 1;
	unsigned _field21 : 1;
	unsigned _field22 : 1;
	unsigned _field23 : 1;
} Server;

typedef struct CAWindowServerImpl {
	CFArrayRef _field1;
	unsigned _field2;
} CAWindowServerImpl;

typedef struct {
	int _field1;
	int _field2;
} XXStruct_K5nmsA;
