#pragma once

#include "Plugin.h"
#include "ofxOpenCv.h"
#include "BlobClasses2d.h"
#include "Keystoner.h"

#include "ofxQtVideoSaver.h"
//#include "videoplayerWrapper.h"
#include "QTKitMovieRenderer.h"

@interface BlobTrackerInstance2d : NSObject {    
    NSView *view;
    NSString * name;
    
    IBOutlet NSSlider * blurSlider;
	IBOutlet NSSlider * thresholdSlider;
	IBOutlet NSButton * activeButton;
	 NSButton * learnBackgroundButton;
    IBOutlet NSButton * drawDebugButton;
	IBOutlet NSSlider * persistentSlider;

    
    NSMutableDictionary * properties;
    
    id cameraInstance;
    int trackerNumber;

    NSMutableArray * persistentBlobs;
	NSMutableArray * blobs;

    int cw, ch;

    ofxCvGrayscaleImage *	grayImage;
    ofxCvGrayscaleImage *	grayImageBlured;	
	ofxCvGrayscaleImage *	grayBg;
    ofxCvGrayscaleImage *	grayDiff;
    
    ofxCvGrayscaleImage * threadGrayDiff;
	ofxCvGrayscaleImage * threadGrayImage;
	
    BOOL threadUpdateContour;
	ofxCvContourFinder 	* contourFinder;
	
    
    BOOL loadBackgroundNow;

    NSThread * thread;
	pthread_mutex_t mutex;

    long unsigned int pidCounter;
	
    ofxQtVideoSaver		*saver;
	BOOL recording;
    
    BOOL live;
    BOOL active;
    
	//videoplayerWrapper * videoPlayer;
    QTKitMovieRenderer * videoPlayer;
    
	NSMutableArray * movies;
	BOOL loadMoviePlease;
	NSString * loadMovieString;
	float millisSinceLastMovieEvent;
    int numFiles;
	unsigned char* pixels;
	unsigned char* rgbTmpPixels;

    IBOutlet NSPopUpButton *moviePopUp;
    IBOutlet NSButton *recordButton;
    
    ofPoint recordingSurfaceCorners[4];
}
@property (assign) IBOutlet NSView *view;
@property (readonly) NSString * name;
@property (retain) NSMutableDictionary * properties;
@property (assign) id cameraInstance;

@property (readonly)  ofxCvGrayscaleImage *	grayDiff;
@property (readonly)  ofxCvGrayscaleImage *	grayBg;
@property (assign) 	IBOutlet NSButton * learnBackgroundButton;
@property (readwrite) BOOL active;

@property (readwrite) int trackerNumber;

- (IBAction)setMovieFile:(id)sender;
- (IBAction)toggleRecord:(id)sender;

-(void) drawInput:(NSRect)rect;
-(void) drawBackground:(NSRect)rect;
-(void) drawDifference:(NSRect)rect;

-(void) drawBlobs:(NSRect)rect warped:(BOOL)warp;
-(void) drawSurfaceMask:(NSRect)rect;

-(void) getSurfaceMaskCorners:(ofPoint*)point clamped:(BOOL)clamp;
-(BOOL) isKinect;
-(BOOL) drawDebug;


-(void) performBlobTracking:(id)param;
-(void) saveBackground;
-(void) loadBackground;

-(void) setup;
-(void) update:(NSDictionary *)drawingInformation;

-(PersistentBlob2d*) getPBlob:(int)num;

-(void) updateMovieList;
@end