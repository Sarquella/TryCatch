//
//  TryCatch.h
//  TryCatch
//
//  Created by Adrià Sarquella on 08/02/2020.
//  Copyright © 2020 Adrià Sarquella. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//MARK: Types

/// Type representing a block containing the code to try
typedef void(^TryBlock)(void);

/**
 Type representing a block containing the code to execute when an exception is thrown
 
 @param exception The exception being thrown
 */
typedef void(^CatchBlock)(NSException*exception);


//MARK: Interface

/// Provides Objective-C like try-catch functionality
@interface TryCatch : NSObject

// Forces to use the [try: block] class method
- (instancetype)init NS_UNAVAILABLE;

/**
 Holds the try block to be executed
 
 @param block The block to try to execute
 */
+ (TryCatch *)try:(TryBlock)block;

/**
 Holds the catch block to be executed in case and exception is thrown
 
 @param block The block to execute when an exception is thrown
 */
- (void)catch:(__attribute__((noescape)) CatchBlock)block;

@end

NS_ASSUME_NONNULL_END
