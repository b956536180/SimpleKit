//
//  SKMenuTableView.h
//  SimpleKit
//
//  Created by SimpleKit on 13-3-12.
//  Copyright (c) 2013 SimpleKit. All rights reserved.
//

#import <UIKit/UIKit.h>

@class SKMenuTableView;

@protocol SKMenuTableViewDataSource <NSObject>

@required
- (NSInteger)numberOfMainMenuItemsInMenuTable:(SKMenuTableView *)menuTable;
- (NSInteger)menuTable:(SKMenuTableView *)menuTable numberOfSubMenuItemsAtMainMenuIndex:(NSInteger)mainIndex;
- (UIView *)menuTable:(SKMenuTableView *)menuTable mainMenuNormalItemViewAtMainMenuIndex:(NSInteger)mainIndex;
- (UIView *)menuTable:(SKMenuTableView *)menuTable mainMenuSelectedItemViewAtMainMenuIndex:(NSInteger)mainIndex;
- (UIView *)menuTable:(SKMenuTableView *)menuTable subMenuNormalItemViewAtMainMenuIndex:(NSInteger)mainIndex subMenuIndex:(NSInteger)subIndex;
- (UIView *)menuTable:(SKMenuTableView *)menuTable subMenuSelectedItemViewAtMainMenuIndex:(NSInteger)mainIndex subMenuIndex:(NSInteger)subIndex;

@optional
- (CGFloat)mainMenuRowHeightInMenuTable:(SKMenuTableView *)menuTable;
- (CGFloat)subMenuRowHeightInMenuTable:(SKMenuTableView *)menuTable;

@end

@protocol SKMenuTableViewDelegate <NSObject>

@optional
- (void)menuTable:(SKMenuTableView *)menuTable didSelectMainMenuItemAtMainMenuIndex:(NSInteger)mainIndex cell:(UITableViewCell *)cell selectedSubMenuIndex:(NSInteger)subIndex;
- (void)menuTable:(SKMenuTableView *)menuTable didSelectSubMenuItemAtMainMenuIndex:(NSInteger)mainIndex subMenuIndex:(NSInteger)subIndex cell:(UITableViewCell *)cell;

@end

// Menu Table
@interface SKMenuTableView : UIView

@property (nonatomic, assign) IBOutlet id<SKMenuTableViewDataSource> dataSource;
@property (nonatomic, assign) IBOutlet id<SKMenuTableViewDelegate> delegate;
@property (nonatomic, assign, readonly) NSInteger numberOfMainMenuItems;
@property (nonatomic, retain, readonly) UITableView *table;

- (void)openMainMenuItemWithMainIndex:(NSInteger)index;
- (void)selectMainMenuItemWithMainMenuIndex:(NSInteger)mainIndex;
- (void)selectMenuItemWithMainMenuIndex:(NSInteger)mainIndex subMenuIndex:(NSInteger)subIndex;
- (void)clearSubmenuSelectedStateWithMainMenuIndex:(NSInteger)index;
- (void)closeMainMenuItems;
- (BOOL)mainMenuHasSubmenusWithMainMenuIndex:(NSInteger)mainIndex;

@end
