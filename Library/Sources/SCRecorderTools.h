//
//  SCRecorderTools.h
//  SCRecorder
//
//  Created by Simon CORSIN on 24/12/14.
//  Copyright (c) 2014 rFlex. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#define SC_OS_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SC_IS_IOS7 SC_OS_GREATER_THAN_OR_EQUAL_TO(@"7.0")
#define SC_IS_IOS8 SC_OS_GREATER_THAN_OR_EQUAL_TO(@"8.0")
#define SC_IS_IOS9 SC_OS_GREATER_THAN_OR_EQUAL_TO(@"9.0")
#define SC_IS_IOS10 SC_OS_GREATER_THAN_OR_EQUAL_TO(@"10.0")


@interface SCRecorderTools : NSObject

/**
 Returns the best session preset that is compatible with all available video
 devices (front and back camera). It will ensure that buffer output from
 both camera has the same resolution.
 */
+ (NSString *__nonnull)bestCaptureSessionPresetCompatibleWithAllDevices;

/**
 Returns the best captureSessionPreset for a device that is equal or under the max specified size
 */
+ (NSString *__nonnull)bestCaptureSessionPresetForDevice:(AVCaptureDevice *__nonnull)device withMaxSize:(CGSize)maxSize;

/**
 Returns the best captureSessionPreset for a device position that is equal or under the max specified size
 */
+ (NSString *__nonnull)bestCaptureSessionPresetForDevicePosition:(AVCaptureDevicePosition)devicePosition withMaxSize:(CGSize)maxSize;

+ (BOOL)formatInRange:(AVCaptureDeviceFormat *__nonnull)format frameRate:(CMTimeScale)frameRate;

+ (BOOL)formatInRange:(AVCaptureDeviceFormat *__nonnull)format frameRate:(CMTimeScale)frameRate dimensions:(CMVideoDimensions)videoDimensions;

+ (CMTimeScale)maxFrameRateForFormat:(AVCaptureDeviceFormat *__nonnull)format minFrameRate:(CMTimeScale)minFrameRate;

+ (AVCaptureDevice *__nonnull)videoDeviceForPosition:(AVCaptureDevicePosition)position;

+ (NSArray *__nonnull)assetWriterMetadata;

@end

@interface NSDate (SCRecorderTools)

- (NSString *__nonnull)toISO8601;

+ (NSDate *__nullable)fromISO8601:(NSString *__nonnull)iso8601;

@end
