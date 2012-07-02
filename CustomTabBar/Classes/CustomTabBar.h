//
//  CustomTabBar.h
//  CustomTabBar
//
//  Created by Peter Boctor on 1/2/11.
//
// Copyright (c) 2011 Peter Boctor
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//

@class CustomTabBar;
@protocol CustomTabBarDelegate

- (UIImage*) imageFor:(CustomTabBar*)tabBar atIndex:(NSUInteger)itemIndex;
- (UIImage*) backgroundImage;
- (UIImage*) selectedItemBackgroundImage:(NSUInteger)itemIndex;
- (UIImage*) glowImage;
- (UIImage*) selectedItemImage;
- (UIImage*) tabBarArrowImage;
- (NSString*) selectedTextForButtonAtIndex:(NSUInteger)itemIndex;
- (NSString*) unselectedTextForButtonAtIndex:(NSUInteger)itemIndex;

@optional
- (void) touchUpInsideItemAtIndex:(NSUInteger)itemIndex;
- (void) touchDownAtItemAtIndex:(NSUInteger)itemIndex;
- (void) otherTouchesAtIndex:(NSUInteger)itemIndex;
- (void) dragEnterExitAtIndex:(NSUInteger)itemIndex;
@end


@interface CustomTabBar : UIView
{
    NSObject <CustomTabBarDelegate> *delegate;
    NSMutableArray* buttons;
}

@property (nonatomic, retain) NSMutableArray* buttons;
@property (nonatomic, strong) NSMutableArray* buttonLabels;
@property (nonatomic, strong) NSMutableArray* buttonSelectedText;
@property (nonatomic, strong) NSMutableArray* buttonUnselectedText;

- (id) initWithItemCount:(NSUInteger)itemCount itemSize:(CGSize)itemSize tag:(NSInteger)objectTag delegate:(NSObject <CustomTabBarDelegate>*)customTabBarDelegate;

- (void) selectItemAtIndex:(NSInteger)index;
- (void) deselectItemAtIndex:(NSInteger)index;
- (void) glowItemAtIndex:(NSInteger)index;
- (void) removeGlowAtIndex:(NSInteger)index;

- (void)selectButton:(UIButton *)button;
- (void)deselectButton:(UIButton *)button;

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

- (void)enableToolbarButton:(BOOL)enable atIndex:(NSUInteger)buttonIndex;

@end
