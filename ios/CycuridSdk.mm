#import "CycuridSdk.h"
#import "cycurid_ios-Swift.h"


@class CycuridObj;

@interface CycuridSdk () <BiometricResultDelegate>

@property (nonatomic, assign) BOOL isConfigured;
@property (nonatomic, strong) RCTPromiseResolveBlock resolveBlock;
@property (nonatomic, strong) RCTPromiseRejectBlock rejectBlock;

@end


@implementation CycuridSdk
RCT_EXPORT_MODULE()

- (void)initCycurid:(NSString *)type options:(NSString *)options resolve:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject { 
    self.resolveBlock = resolve;
    self.rejectBlock = reject;

    NSError *jsonError;
    NSData *objectData = [options dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *json = [NSJSONSerialization JSONObjectWithData:objectData
                                          options:NSJSONReadingMutableContainers
                                            error:&jsonError];

    [CycuridObj ConfigureWithApiKey:[json valueForKey:@"apiKey"]
                secretKey:[json valueForKey:@"secretKey"]
                userId: [json valueForKey:@"userId"] completion:^(BOOL success, NSError * _Nullable error) {
        
        if (success) {
            [CycuridObj beginProcessWithFlow:type delegateClass:self];
        } else {
            if (reject) {
                self.rejectBlock(@"CONFIG_ERROR", error.localizedDescription, error);
                self.resolveBlock = nil;
                self.rejectBlock = nil;
            }
        }
    }];
}

- (void)biometricResultWithResult:(NSString * _Nonnull)result { 
    NSLog(@"We got ourselves a result: %@", result);
    if (self.resolveBlock) {
        self.resolveBlock(result);
        self.resolveBlock = nil;
        self.rejectBlock = nil;
    }
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativeCycuridSdkSpecJSI>(params);
}

@end
