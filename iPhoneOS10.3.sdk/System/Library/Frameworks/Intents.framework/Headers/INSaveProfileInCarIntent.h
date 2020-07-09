//
//  INSaveProfileInCarIntent.h
//  Intents
//
//  Copyright © 2016 Apple. All rights reserved.
//

#import <Intents/INIntent.h>
#import <Intents/INIntentResolutionResult.h>

@class INIntegerResolutionResult;
@class INStringResolutionResult;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0))
API_UNAVAILABLE(watchos, macosx)
@interface INSaveProfileInCarIntent : INIntent

- (instancetype)initWithProfileNumber:(nullable NSNumber *)profileNumber
                          profileName:(nullable NSString *)profileName NS_DESIGNATED_INITIALIZER NS_REFINED_FOR_SWIFT API_AVAILABLE(ios(10.2));

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSNumber *profileNumber NS_REFINED_FOR_SWIFT;

@property (readonly, copy, nullable, NS_NONATOMIC_IOSONLY) NSString *profileName API_AVAILABLE(ios(10.2));

@end

@class INSaveProfileInCarIntentResponse;

/*!
 @brief Protocol to declare support for handling an INSaveProfileInCarIntent 
 @abstract By implementing this protocol, a class can provide logic for resolving, confirming and handling the intent.
 @discussion The minimum requirement for an implementing class is that it should be able to handle the intent. The resolution and confirmation methods are optional. The handling method is always called last, after resolving and confirming the intent.
 */

API_AVAILABLE(ios(10.0))
API_UNAVAILABLE(watchos, macosx)
@protocol INSaveProfileInCarIntentHandling <NSObject>

@required

/*!
 @brief handling method

 @abstract Execute the task represented by the INSaveProfileInCarIntent that's passed in
 @discussion Called to actually execute the intent. The app must return a response for this intent.

 @param  saveProfileInCarIntent The input intent
 @param  completion The response handling block takes a INSaveProfileInCarIntentResponse containing the details of the result of having executed the intent

 @see  INSaveProfileInCarIntentResponse
 */

- (void)handleSaveProfileInCar:(INSaveProfileInCarIntent *)intent
                    completion:(void (^)(INSaveProfileInCarIntentResponse *response))completion NS_SWIFT_NAME(handle(saveProfileInCar:completion:));

@optional

/*!
 @brief Confirmation method
 @abstract Validate that this intent is ready for the next step (i.e. handling)
 @discussion Called prior to asking the app to handle the intent. The app should return a response object that contains additional information about the intent, which may be relevant for the system to show the user prior to handling. If unimplemented, the system will assume the intent is valid following resolution, and will assume there is no additional information relevant to this intent.

 @param  saveProfileInCarIntent The input intent
 @param  completion The response block contains an INSaveProfileInCarIntentResponse containing additional details about the intent that may be relevant for the system to show the user prior to handling.

 @see INSaveProfileInCarIntentResponse

 */

- (void)confirmSaveProfileInCar:(INSaveProfileInCarIntent *)intent
                     completion:(void (^)(INSaveProfileInCarIntentResponse *response))completion NS_SWIFT_NAME(confirm(saveProfileInCar:completion:));

/*!
 @brief Resolution methods
 @abstract Determine if this intent is ready for the next step (confirmation)
 @discussion Called to make sure the app extension is capable of handling this intent in its current form. This method is for validating if the intent needs any further fleshing out.

 @param  saveProfileInCarIntent The input intent
 @param  completion The response block contains an INIntentResolutionResult for the parameter being resolved

 @see INIntentResolutionResult

 */

- (void)resolveProfileNumberForSaveProfileInCar:(INSaveProfileInCarIntent *)intent
                                 withCompletion:(void (^)(INIntegerResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveProfileNumber(forSaveProfileInCar:with:));

- (void)resolveProfileNameForSaveProfileInCar:(INSaveProfileInCarIntent *)intent
                               withCompletion:(void (^)(INStringResolutionResult *resolutionResult))completion NS_SWIFT_NAME(resolveProfileName(forSaveProfileInCar:with:))API_AVAILABLE(ios(10.2));

@end

NS_ASSUME_NONNULL_END