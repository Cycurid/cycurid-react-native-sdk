//
//  CycuridClass.h
//  cycurid-ios
//
//  Created by Ekam Singh on 2025-01-07.
//

#ifndef CycuridClass_h
#define CycuridClass_h

#import <Foundation/Foundation.h>

typedef void (^BiometricCompletionBlock)(NSString * _Nullable result, NSError * _Nullable error);

@interface CycuridClass : NSObject

@property (nonatomic, copy) BiometricCompletionBlock biometricCompletion;

- (void)configureWithApiKey:(NSString *)apiKey
                  secretKey:(NSString *)secretKey
                     userId:(NSString *)userId
                 completion:(void (^)(BOOL success, NSError *error))completion;

- (void)beginProcessWithFlow:(NSString *)flow
               delegateClass:(id)delegateClass;

@end


#endif /* CycuridClass_h */
