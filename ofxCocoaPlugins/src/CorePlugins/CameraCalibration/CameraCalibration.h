#pragma once
#import <ofxCocoaPlugins/Plugin.h>
#import <ofxCocoaPlugins/Cameras.h>
#import <ofxCocoaPlugins/CameraCalibrationObject.h>
#define ProjNumber 0

@interface CameraCalibration : ofPlugin {
    int controlWidth;
    int controlHeight;
    
    NSArrayController * camerasArrayController;
    NSDictionaryController * surfacesArrayController;
    
    NSMutableDictionary * calibrationObjects;
    CameraCalibrationObject * selectedCalibrationObject;
    
    BOOL changingSurface;
    BOOL drawDebug;
    BOOL drawUndistorted;
    
    ofImage * handleImage;   
    float mouseLastX,mouseLastY;
    int draggedPoint;

}

@property (readonly) NSArrayController * camerasArrayController;
@property (readonly) NSArrayController * surfacesArrayController;
@property (retain, readwrite) CameraCalibrationObject * selectedCalibrationObject;
@property (readwrite) BOOL changingSurface;
@property (readwrite) BOOL drawDebug;
@property (readwrite) BOOL drawUndistorted;

@property (retain, readonly) NSMutableDictionary * calibrationObjects;

-(CameraCalibrationObject *) calibrationForCamera:(Camera*)camera surface:(NSString*)surface;
@end
