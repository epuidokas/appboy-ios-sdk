#import <Foundation/Foundation.h>
#import "ABKFeedController.h"

/*
 * Appboy Public API: ABKCard
 */
NS_ASSUME_NONNULL_BEGIN
@interface ABKCard : NSObject <NSCopying, NSCoding>
/*
 * Card's ID.
 */
@property (readonly) NSString *idString;

/*
 * This property reflects if the card is read or unread by the user.
 */
@property (nonatomic) BOOL viewed;

/*
 * The property is the unix timestamp of the card's creation time from Appboy dashboard.
 */
@property (nonatomic, readonly) double created;

/*
 * The property is the unix timestamp of the card's latest update time from Appboy dashboard.
 */
@property (nonatomic, readonly) double updated;

/*
 * The categories assigned to the card.
 */
@property ABKCardCategory categories;

/*
 * The property is the unix timestamp of the card's expiration time. When the value is less than 0, it means the card
 * doesn't an expire date.
 */
@property (readonly) double expiresAt;

/*!
 * This property carries extra data in the form of an NSDictionary which can be sent down via the Appboy Dashboard.
 * You may want to design and implement a custom handler to access this data depending on your use case.
 */
@property (nullable) NSDictionary *extras;

/*
 * @param cardDictionary The dictionary for card deserialization.`
 *
 * Deserializes the dictionary to a card for use by wrappers such as Appboy's Unity SDK for iOS.
 * When the deserialization isn't successful, this method returns nil; otherwise, it returns the deserialized card.
 */
+ (nullable ABKCard *) deserializeCardFromDictionary:(nullable NSDictionary *)cardDictionary;

/*
 * Serializes the card to binary data for use by wrappers such as Appboy's Unity SDK for iOS.
 */
- (nullable NSData *) serializeToData;

/*
 * Manually log an impression to Appboy for the card.
 * This should only be used for custom news feed view controller. ABKFeedViewController already has card impression logging.
 */
- (void) logCardImpression;

/*
 * Manually log a click to Appboy for the card.
 * * This should only be used for custom news feed view controller. ABKFeedViewController already has card click logging.
 */
- (void) logCardClicked;

- (BOOL) hasSameId:(ABKCard *)card;
@end
NS_ASSUME_NONNULL_END
