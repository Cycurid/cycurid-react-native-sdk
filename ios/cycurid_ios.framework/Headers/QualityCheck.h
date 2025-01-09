//
//  QualityCheck.h
//  TrainingApp
//
//  Created by Sina Salehian on 11/23/20.
//

#ifndef QualityCheck_h
#define QualityCheck_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface QualityWrapper : NSObject

@property bool first_time_loading;

+(nonnull NSString *)openCVVersionString;
+(nonnull UIImage *)cvtColorBGR2GRAY:(nonnull UIImage *)image;
//+(bool)reSampleFace:(nonnull UIImage *)rawImage;
+(bool)getInfoDump12: (nonnull UIImage *)rawImage;
+ (bool)getInfoDump11:(nonnull UIImage*)image;
+(bool)getInfoDump10: (nonnull UIImage *)rawImage blurL:(float *)blur_laplac blurC:(float *)blur_canny glare:(float *)bright_glare xmin:(float)xminP ymin:(float)yminP xmax:(float)xmaxP ymax:(float)ymaxP;
- (NSMutableArray *)getInfoDump8:(nonnull UIImage*)image;
- (NSMutableArray *)getInfoDump7:(nonnull UIImage*)image;
- (UIImage *)getInfoDump6:(nonnull UIImage*)image ymin:(float)yminP ymax:(float)ymaxP xmin:(float)xminP xmax:(float)xmaxP ratio:(float)ratio;
- (UIImage *)getInfoDump5:(nonnull UIImage*)image ymin:(float)yminP ymax:(float)ymaxP xmin:(float)xminP xmax:(float)xmaxP ratio:(float)ratio;
- (UIImage *)getInfoDump4:(nonnull UIImage*)image ymin:(float)yminP ymax:(float)ymaxP xmin:(float)xminP xmax:(float)xmaxP ratio:(float)ratio;
- (UIImage *)getInfoDump3:(nonnull UIImage*)image ymin:(float)yminP ymax:(float)ymaxP xmin:(float)xminP xmax:(float)xmaxP;
- (UIImage *)getInfoDump2:(nonnull UIImage*)image xmin:(float)xminP ymin:(float)yminP xmax:(float)xmaxP ymax:(float)ymaxP;
- (bool)getInfoDump:(nonnull UIImage*)image ymin:(float)yminP ymax:(float)ymaxP xmin:(float)xminP xmax:(float)xmaxP total:(float *)totalResult;

@end

#endif /* QualityCheck_h */
