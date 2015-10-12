//
//  SKSortTableView.h
//  SimpleKit
//
//  Created by simplekit on 13-3-3.
//  Copyright (c) 2013 simplekit. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, SKSortTableViewSortType) {
    SKSortTableViewSortTypeNumber = 0,
    SKSortTableViewSortTypeString
};

@class SKSortTableView;

@protocol SKSortTableViewDataSource <NSObject>

@required
- (NSInteger)numberOfColumnsInSortTableView:(SKSortTableView *)sortTable;
- (NSInteger)numberOfRowsInSortTableView:(SKSortTableView *)sortTable;
- (NSString *)sortTable:(SKSortTableView *)sortTable titleForHeaderAtColumnIndex:(NSInteger)columnIndex;
- (CGFloat)sortTable:(SKSortTableView *)sortTable widthForColumnIndex:(NSInteger)columnIndex;
- (UIView *)sortTable:(SKSortTableView *)sortTable viewForRowIndex:(NSInteger)rowIndex columnIndex:(NSInteger)columnIndex;

@optional
- (CGFloat)heightForHeaderViewInSortTable:(SKSortTableView *)sortTable;
- (UIView *)sortTable:(SKSortTableView *)sortTable viewForHeaderAtColumnIndex:(NSInteger)columnIndex;
////////////////////////////////////////////////////////////////////////////////
// Need to be set when sorting
- (BOOL)sortTable:(SKSortTableView *)sortTable isSortForColumnIndex:(NSInteger)columnIndex;
- (SKSortTableViewSortType)sortTable:(SKSortTableView *)sortTable sortTypeForColumnIndex:(NSInteger)columnIndex;
// The returned array is an two-dimensional array
- (NSMutableArray *)dataArrayToSortInSortTable:(SKSortTableView *)sortTable;
- (void (^)(NSMutableArray *))functionForPassingDataInSortTable:(SKSortTableView *)sortTable;
- (NSInteger)sortTable:(SKSortTableView *)sortTable sortIndexForColumnIndex:(NSInteger)columnIndex;
////////////////////////////////////////////////////////////////////////////////
@end

@protocol SKSortTableViewDelegate <NSObject>

@optional
- (void)sortTable:(SKSortTableView *)sortTable didSelectRowAtIndexPath:(NSIndexPath *)indexPath withTableView:(UITableView *)tableView;

@end

@interface SKSortTableView : UIView

@property (nonatomic, assign) IBOutlet id<SKSortTableViewDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<SKSortTableViewDelegate> delegate;
@property (nonatomic, retain) UIImage *sortAseIcon;
@property (nonatomic, retain) UIImage *sortDescIcon;
@property (nonatomic,assign) UITableViewCellSelectionStyle selectionStyle;

- (void)reloadData;

@end
