//
//  NetworkUtils.h
//  cycurid-ios
//
//  Created by Ekam Singh on 2024-07-22.
//

#ifndef NetworkUtils_h
#define NetworkUtils_h

#import <Foundation/Foundation.h>

@class NetworkUtils;
@interface NetworkUtils : NSObject

//-(instancetype)init;

typedef void(^postRequestBlock)(NSString* _Nonnull res, int status);
-(void)makeRequest:(NSString *_Nonnull) params completion:(postRequestBlock _Nonnull )completed;

+ (void)setIsSandbox:(BOOL)value;
+ (BOOL)isSandbox;
@end

#endif /* NetworkUtils_h */
