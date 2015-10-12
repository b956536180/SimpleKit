// SHLineGraphView.h
//
// Copyright (c) 2014 Shan Ul Haq (http://grevolution.me)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#import <UIKit/UIKit.h>

@class SKPlot;

@interface SKLineGraphView : UIView
{
    CGPoint currentLoc;
    BOOL isMovement;
}
/**
 *  an Array of dictionaries specifying the key/value pair where key is the object which will identify a particular
 *  x point on the x-axis line. and the value is the label which you want to show on x-axis against that point on x-axis.
 *  the keys are important here as when plotting the actual points on the graph, you will have to use the same key to
 *  specify the point value for that x-axis point.
 */

@property (nonatomic,strong) void(^ myBlock)(void);

@property (nonatomic, strong) NSArray *xAxisValues;

/**
 *  the maximum y-value possible in the graph. make sure that the y-value is not in the plotting points is not greater
 *  then this number. otherwise the graph plotting will show wrong results.
 */
@property (nonatomic, strong) NSNumber *yAxisRange;

/**
 *  y-axis values are calculated according to the yAxisRange passed. so you do not have to pass the explicit labels for 
 *  y-axis, but if you want to put any suffix to the calculated y-values, you can mention it here (e.g. K, M, Kg ...)
 */
@property (nonatomic, strong) NSString *yAxisSuffix;

/**
 *  readyonly dictionary that stores all the plots in the graph.
 */
@property (nonatomic, readonly, strong) NSMutableArray *plots;

/**
 *  theme attributes dictionary. you can specify graph theme releated attributes in this dictionary. if this property is 
 *  nil, then a default theme setting is applied to the graph.
 */
@property (nonatomic, strong) NSDictionary *themeAttributes;

@property (nonatomic, strong) SKPlot *longPlot;

/**
 *  this method will add a Plot to the graph.
 *
 *  @param newPlot the Plot that you want to draw on the Graph.
 */
- (void)addPlot:(SKPlot *)newPlot;

/**
 *  this method is the actual method which starts the drawing of the graph and does all the magic. call this method when
 *  you are ready and want to show the graph.
 */
- (void)setupTheView;

- (void)updataTheView:(SKPlot *)plot with:(NSArray *)array ;


//===== Theme Attribute Keys =====

/**
 *  x-axis label color key. use this to define the x-axis color of the plot (UIColor*)
 */
UIKIT_EXTERN NSString *const kXAxisLabelColorKey;

/**
 *  x-axis label font key. use this to define the font of the x-axis labels. (UIFont*)
 */
UIKIT_EXTERN NSString *const kXAxisLabelFontKey;

/**
 *  y-axis label color key. use this to define the y-axis label color of the plot (UIColor*)
 */
UIKIT_EXTERN NSString *const kYAxisLabelColorKey;

/**
 *  y-axis label font key. use this to define the font of the y-axis labels. (UIFont*)
 */
UIKIT_EXTERN NSString *const kYAxisLabelFontKey;

/**
 *  y-axis label side margin key. use this to define the font of the y-axis labels side margin. the value will
 *  be equally divided into the both sides of the label. (NSNumber*)
 */
UIKIT_EXTERN NSString *const kYAxisLabelSideMarginsKey;


UIKIT_EXTERN NSString *const kYAxisLabelSideMargXinsKey;



/**
 *  plot background line stroke color key. use this to define the stroke color of the background lines in plot (UIColor*)
 */
UIKIT_EXTERN NSString *const kPlotBackgroundLineColorKye;
/**
 *  是都显示X坐标轴
 */
UIKIT_EXTERN NSString *const kISXLabel;

/**
 *  开始运动点的速度
 */
UIKIT_EXTERN NSString *const kPointSpeed;

/**
 *  y轴的做标数量
 */
UIKIT_EXTERN NSString *const kYPointCount;

/**
 *  是都显示坐标点
 */
UIKIT_EXTERN NSString *const kISShowPoint;

/**
 *  垂直高度的Bug
 */
UIKIT_EXTERN NSString *const kYHeight;

/**
 *  x轴间隔个数限制
 */
UIKIT_EXTERN NSString *const kXInterval;


/**
 *  是否有滑动线
 */
UIKIT_EXTERN NSString *const kXfingerLine;





@end
