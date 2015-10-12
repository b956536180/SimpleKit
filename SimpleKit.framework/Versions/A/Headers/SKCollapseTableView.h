//
//  SKCollapseTableView.h
//  SimpleKit
//
//  Created by simplekit on 13-3-1.
//  Copyright (c) 2013 simplekit. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SKCollapseTableView;

@protocol SKCollapseTableViewDataSource <NSObject>

@required
- (NSInteger)numberOfSectionsInCollapseTable:(SKCollapseTableView *)collapseTable;
- (UIView *)collapseTable:(SKCollapseTableView *)collapseTable viewForCellInSection:(NSInteger)section;

@optional
- (UIView *)collapseTable:(SKCollapseTableView *)collapseTable viewForHeaderInSection:(NSInteger)section;
- (CGFloat)collapseTable:(SKCollapseTableView *)collapseTable heightForHeaderInSection:(NSInteger)section;
- (CGFloat)collapseTable:(SKCollapseTableView *)collapseTable heightForCellInSection:(NSInteger)section;

@end

@protocol SKCollapseTableViewDelegate <NSObject>

@optional
- (void)collapseTable:(SKCollapseTableView *)collapseTable didClickAtSectionIndex:(NSInteger)sectionIndex;

@end

@interface SKCollapseTableView : UIView

@property (nonatomic, assign) IBOutlet id<SKCollapseTableViewDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<SKCollapseTableViewDelegate> delegate;
@property (nonatomic, retain) UITableView *table;

- (void)openCellInSection:(NSInteger)section;
- (void)closeCellInSection:(NSInteger)section;
- (void)openAllCell;
- (void)closeAllCell;

@end