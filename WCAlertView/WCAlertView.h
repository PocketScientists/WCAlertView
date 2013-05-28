//
//  WCAlertView.h
//  WCAlertView
//
//  Created by Michał Zaborowski on 18/07/12.
//  Copyright (c) 2012 Michał Zaborowski. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <UIKit/UIKit.h>

@class WCAlertView;

typedef NS_ENUM(NSInteger, WCAlertViewStyle)
{
    WCAlertViewStyleDefault = 0,
    
    WCAlertViewStyleWhite,
    WCAlertViewStyleWhiteHatched,
    WCAlertViewStyleBlack,
    WCAlertViewStyleBlackHatched,
    WCAlertViewStyleViolet,
    WCAlertViewStyleVioletHatched,
    
    WCAlertViewStyleCustomizationBlock,
};

typedef void(^CustomizationBlock)(WCAlertView *alertView);

@interface WCAlertView : UIAlertView

/*
 *  Predefined alert styles
 */
@property (nonatomic,assign) WCAlertViewStyle style UI_APPEARANCE_SELECTOR;

/*
 *  Title and message label styles
 */
@property (nonatomic,strong) UIColor *labelTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *labelShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGSize   labelShadowOffset UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIFont  *titleFont UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIFont  *messageFont UI_APPEARANCE_SELECTOR;

/*
 *  Button styles
 */
@property (nonatomic,strong) UIColor *buttonTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIFont  *buttonFont UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *buttonShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGSize   buttonShadowOffset UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGFloat  buttonShadowBlur UI_APPEARANCE_SELECTOR;

/*
 *  Background gradient colors and locations
 */
@property (nonatomic,strong) NSArray *gradientLocations UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) NSArray *gradientColors UI_APPEARANCE_SELECTOR;

@property (nonatomic,assign) CGFloat cornerRadius UI_APPEARANCE_SELECTOR;
/*
 * Inner frame shadow (optional)
 * Stroke path to cover up pixialation on corners from clipping!
 */
@property (nonatomic,strong) UIColor *innerFrameShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *innerFrameStrokeColor UI_APPEARANCE_SELECTOR;

/*
 * Hatched lines
 */
@property (nonatomic,strong) UIColor *verticalLineColor UI_APPEARANCE_SELECTOR;

@property (nonatomic,strong) UIColor *hatchedLinesColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *hatchedBackgroundColor UI_APPEARANCE_SELECTOR;

/*
 *  Outer frame color
 */
@property (nonatomic,strong) UIColor *outerFrameColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGFloat  outerFrameLineWidth UI_APPEARANCE_SELECTOR;
@property (nonatomic,strong) UIColor *outerFrameShadowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGSize   outerFrameShadowOffset UI_APPEARANCE_SELECTOR;
@property (nonatomic,assign) CGFloat  outerFrameShadowBlur UI_APPEARANCE_SELECTOR;

/*
 *  Setting default appearance for all WCAlertView's
 */
+ (void)setDefaultStyle:(WCAlertViewStyle)style;
+ (void)setDefaultCustomiaztonBlock:(CustomizationBlock)block;


+ (id)showAlertWithTitle:(NSString *)title message:(NSString *)message customizationBlock:(void (^)(WCAlertView *alertView))customization
         completionBlock:(void (^)(NSUInteger buttonIndex, WCAlertView *alertView))block
       cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSString *)otherButtonTitles, ... NS_REQUIRES_NIL_TERMINATION;


@end
