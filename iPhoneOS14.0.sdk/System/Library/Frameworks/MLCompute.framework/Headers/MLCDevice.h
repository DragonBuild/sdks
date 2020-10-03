//
//  MLCDevice.h
//  MLCompute
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/Metal.h>
#import <MLCompute/MLCDefines.h>
#import <MLCompute/MLCTypes.h>

NS_ASSUME_NONNULL_BEGIN

/*! @class      MLCDevice
    @discussion A device that will be used to execute a neural network
 */
MLCOMPUTE_CLASS_AVAILABLE_STARTING(macos(10.16), ios(14.0), tvos(14.0))
@interface MLCDevice : NSObject<NSCopying>

/*! @property   type
    @abstract   The device type.
    @discussion Recommend that developers use MLCDeviceTypeAny as the device type.
                This will ensure that MLCompute will select the best device to execute the neural network.
                If developers want to be able to control device selection, they can select CPU or GPU and
                for the GPU, they can also select a specific Metal device.
 */
@property (readonly, nonatomic) MLCDeviceType type;

@property (readonly, nonatomic) NSArray<id<MTLDevice>> *gpuDevices;

/*! @abstract   Creates a device which uses the CPU.
 *  @return     A new device.
 */
+ (instancetype)cpuDevice;

/*! @abstract   Creates a device which uses a GPU, if any.
    @return     A new device, or `nil` if no GPU exists.
 */
+ (instancetype _Nullable)gpuDevice;

/*! @abstract   Create a MLCDevice object
    @param      type    A device type
    @return     A new device object
 */
+ (instancetype _Nullable)deviceWithType:(MLCDeviceType)type;

/*! @abstract   Create a MLCDevice object
    @discussion This method can be used by developers to select specific GPUs
    @param      gpus    List of Metal devices
    @return     A new device object
 */
+ (instancetype _Nullable)deviceWithGPUDevices:(NSArray<id<MTLDevice>> *)gpus;

@end

NS_ASSUME_NONNULL_END
