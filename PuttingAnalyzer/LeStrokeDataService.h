/*
 *  LeStrokeDataService.h
 *  PuttingAnalyzer
 *
 *  Created by Bradley Weiers on Jan 6, 2014.
 *  Copyright University of Saskatchewan. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>


/****************************************************************************/
/*						Service Characteristics								*/
/****************************************************************************/
// Declare as GLOBAL
//extern NSString *STROKE_DATA_SERVICE_UUID;                 // DEADF154-0000-0000-0000-0000DEADF154     Service UUID
//extern NSString *DISTANCE_CHARACTERISTIC_UUID;   // CCCCFFFF-DEAD-F154-1319-740381000000     Current Distance Characteristic
//extern NSString *kMinimumTemperatureCharacteristicUUIDString;   // C0C0C0C0-DEAD-F154-1319-740381000000     Minimum Temperature Characteristic
//extern NSString *kMaximumTemperatureCharacteristicUUIDString;   // EDEDEDED-DEAD-F154-1319-740381000000     Maximum Temperature Characteristic
//extern NSString *kAlarmCharacteristicUUIDString;                // AAAAAAAA-DEAD-F154-1319-740381000000     Alarm Characteristic

extern NSString *kStrokeDataServiceEnteredBackgroundNotification;
extern NSString *kStrokeDataServiceEnteredForegroundNotification;

/****************************************************************************/
/*								Protocol									*/
/****************************************************************************/
@class LeStrokeDataService;

//typedef enum {
//    kAlarmHigh  = 0,
//    kAlarmLow   = 1,
//} AlarmType;

@protocol StrokeDataProtocol<NSObject>
//- (void) alarmService:(LeStrokeDataService*)service didSoundAlarmOfType:(AlarmType)alarm;
//- (void) alarmServiceDidStopAlarm:(LeStrokeDataService*)service;
- (void) strokeDataServiceDidChangeDistance:(LeStrokeDataService*)service;
//- (void) alarmServiceDidChangeTemperatureBounds:(LeStrokeDataService*)service;
- (void) strokeDataServiceDidChangeStatus:(LeStrokeDataService*)service;
- (void) strokeDataServiceDidReset;
@end


/****************************************************************************/
/*						Temperature Alarm service.                          */
/****************************************************************************/
@interface LeStrokeDataService : NSObject

- (id) initWithPeripheral:(CBPeripheral *)peripheral controller:(id<StrokeDataProtocol>)controller;
- (void) reset;
- (void) start;

/* Querying Sensor */
@property (readonly) CGFloat distance;
//@property (readonly) CGFloat minimumTemperature;
//@property (readonly) CGFloat maximumTemperature;

/* Set the alarm cutoffs */
//- (void) writeLowAlarmTemperature:(int)low;
//- (void) writeHighAlarmTemperature:(int)high;

/* Behave properly when heading into and out of the background */
- (void)enteredBackground;
- (void)enteredForeground;

@property (readonly) CBPeripheral *peripheral;
@end
