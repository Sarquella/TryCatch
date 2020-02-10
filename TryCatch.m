//
//  TryCatch.m
//  TryCatch
//
//  Created by Adrià Sarquella on 08/02/2020.
//  Copyright © 2020 Adrià Sarquella. All rights reserved.
//

#import "TryCatch.h"

@interface TryCatch()
    @property (nonatomic, copy) TryBlock tryBlock;
@end

@implementation TryCatch

- (instancetype)initTryBlock:(TryBlock)tryBlock {
    self = [super init];
    if (self) {
        self.tryBlock = tryBlock;
    }
    return self;
}

+ (TryCatch*)try:(TryBlock)block {
    return [[TryCatch alloc] initTryBlock:block];
}

- (void)catch:(__attribute__((noescape)) void(^)(NSException*exception))block {
    @try {
        self.tryBlock();
    } @catch (NSException *exception) {
        block(exception);
    }
}

@end
