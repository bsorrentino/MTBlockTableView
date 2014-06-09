//
//  MTBlockTableView.h
//  MTTableViewController
//
//  Created by Parker Wightman on 8/10/12.
//  Copyright (c) 2012 Mysterious Trousers. All rights reserved.
//

@interface MTBlockTableView : UITableView <UITableViewDelegate, UITableViewDataSource>

#pragma mark UITableViewDataSource blocks (required)

@property (nonatomic, strong) NSInteger (^numberOfRowsInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) UITableViewCell * (^cellForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);



#pragma mark UITableViewDataSource blocks (optional)

@property (nonatomic, strong) NSInteger (^numberOfSectionsInTableViewBlock)(UITableView *tableView);
@property (nonatomic, strong) NSString * (^titleForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) NSString * (^titleForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) BOOL (^canEditRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) BOOL (^canMoveRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) NSArray * (^sectionIndexTitlesBlock)(UITableView *tableView);
@property (nonatomic, strong) void (^commitEditingStyleForRowAtIndexPathBlock)(UITableView *tableView, UITableViewCellEditingStyle editingStyle, NSIndexPath *indexPath);
@property (nonatomic, strong) void (^moveRowAtIndexPathToIndexPathBlock)(UITableView *tableView, NSIndexPath *sourceIndexPath, NSIndexPath *destinationIndexPath);
@property (nonatomic, strong) NSInteger (^sectionForSectionIndexTitleAtIndex)(UITableView *tableView, NSString *title, NSInteger index);


#pragma mark - UITableViewDelegate blocks (optional)

@property (nonatomic, strong) void (^accessoryButtonTappedForRowWithIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) BOOL (^canPerformActionForRowAtIndexPathWithSenderBlock)(UITableView *tableView, SEL action, NSIndexPath *indexPath, id sender);
@property (nonatomic, strong) void (^didDeselectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) void (^didEndEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) void (^didSelectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) UITableViewCellEditingStyle (^editingStyleForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) CGFloat (^heightForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) CGFloat (^heightForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) CGFloat (^heightForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) NSInteger (^indentationLevelForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) void (^performActionForRowAtIndexPathWithSenderBlock)(UITableView *tableView, SEL action, NSIndexPath *indexPath, id sender);
@property (nonatomic, strong) BOOL (^shouldIndentWhileEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) BOOL (^shouldShowMenuForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) NSIndexPath * (^targetIndexPathForMoveFromRowAtIndexPathToProposedIndexPathBlock)(UITableView *tableView, NSIndexPath *sourceIndexPath, NSIndexPath *proposedDestinationIndexPath);
@property (nonatomic, strong) NSString * (^titleForDeleteConfirmationButtonForRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) UIView * (^viewForFooterInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) UIView * (^viewForHeaderInSectionBlock)(UITableView *tableView, NSInteger section);
@property (nonatomic, strong) void (^willBeginEditingRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) NSIndexPath * (^willDeselectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);
@property (nonatomic, strong) void (^willDisplayCellForRowAtIndexPathBlock)(UITableView *tableView, UITableViewCell *cell, NSIndexPath *indexPath);
@property (nonatomic, strong) NSIndexPath * (^willSelectRowAtIndexPathBlock)(UITableView *tableView, NSIndexPath *indexPath);

#pragma mark - UIScrollViewDelegate blocks (optional)

// any offset changes
@property (nonatomic, strong) void (^scrollViewDidScroll)(UIScrollView *scrollView);
// any zoom scale changes
@property (nonatomic, strong) void (^scrollViewDidZoom)(UIScrollView *scrollView);

// called on start of dragging (may require some time and or distance to move)
@property (nonatomic, strong) void (^scrollViewWillBeginDragging)(UIScrollView *scrollView);

// called on finger up if the user dragged. velocity is in points/millisecond. targetContentOffset may be changed to adjust where the scroll view comes to rest
@property (nonatomic, strong) void (^scrollViewWillEndDragging)(UIScrollView *scrollView, CGPoint velocity, CGPoint * targetContentOffset);

// called on finger up if the user dragged. decelerate is true if it will continue moving afterwards
@property (nonatomic, strong) void (^scrollViewDidEndDragging)(UIScrollView *scrollView,  BOOL decelerate);

// called on finger up as we are moving
@property (nonatomic, strong) void (^scrollViewWillBeginDecelerating)(UIScrollView *scrollView);

// called when scroll view grinds to a halt
@property (nonatomic, strong) void (^scrollViewDidEndDecelerating)(UIScrollView *scrollView);

// called when setContentOffset/scrollRectVisible:animated: finishes. not called if not animating
@property (nonatomic, strong) void (^scrollViewDidEndScrollingAnimation)(UIScrollView *scrollView);

// return a view that will be scaled. if delegate returns nil, nothing happens
@property (nonatomic, strong) UIView * (^viewForZoomingInScrollView)(UIScrollView *scrollView);

// called before the scroll view begins zooming its content
@property (nonatomic, strong) void (^scrollViewWillBeginZooming)(UIScrollView *scrollView, UIView * view);
// scale between minimum and maximum. called after any 'bounce' animations
@property (nonatomic, strong) void (^scrollViewDidEndZooming)(UIScrollView *scrollView, UIView * view, CGFloat scale);

@property (nonatomic, strong) BOOL (^scrollViewShouldScrollToTop)(UIScrollView *scrollView);
// called when scrolling animation finished. may be called immediately if already at top
@property (nonatomic, strong) void (^scrollViewDidScrollToTop)(UIScrollView *scrollView);


@end

