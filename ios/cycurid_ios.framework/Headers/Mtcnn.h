//
//  Mtcnn.h
//  TrainingApp
//
//  Created by Ekam  on 2020-05-04.
//

#ifndef Mtcnn_h
#define Mtcnn_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class NCNNWrapper;
@interface NCNNWrapper : NSObject


@property float real;
@property float total;

-(instancetype)init;
-(nonnull NSString *)openCVVersionString;
-(nonnull UIImage *)cvtColorBGR2GRAY:(nonnull UIImage *)input_image;

-(UIImage *)getInfo85: (nonnull UIImage *)rawImage
                    andTopPos: (CGFloat)ovalTop
                    andBottomPos: (CGFloat)ovalBot
                    andRightPos: (CGFloat)ovalRight
                    andLeftPos: (CGFloat)ovalLeft
                    andCentreX: (CGFloat)centreX
                    andCentreY: (CGFloat)centreY;
-(nonnull NSString *)getInfo83;
-(int)getInfo82;
-(void)getInfo81;

-(bool)getInfo76;
-(int)getInfo75;
-(bool)getInfo74;
-(bool)getInfo73;
-(NSString *_Nonnull)getInfo72;
-(bool)getInfo71;
-(float)getInfo70;
-(bool)getInfo69;
-(int)getInfo68;

-(int)getInfo;
-(int)getInfo3;
-(int)getInfo2;
-(int)getInfo4;
-(int)getInfo6;

-(bool)getInfo24;

-(void)getInfo62;
-(bool)getInfo63:(nonnull UIImage *)input_image;
-(bool)getInfo64: (nonnull UIImage *)rawImage;
-(NSString *_Nonnull)getInfo66;
-(NSString *_Nonnull)getInfo67;

-(UIImage *)testFFT: (nonnull UIImage *)rawImage;
-(double)returnScore;
-(void)resetScore;


@end

#endif
