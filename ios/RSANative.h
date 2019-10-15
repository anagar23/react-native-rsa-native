//
//  RSA.h
//  RNRSA
//
//  Created by Amitay Molko on 24/06/2017.
//  Copyright © 2017 Facebook. All rights reserved.
//

@import Foundation;

@interface RSANative : NSObject

@property (nonatomic) NSString *publicKey;
@property (nonatomic) NSString *privateKey;

- (instancetype)initWithKeyTag:(NSString *)keyTag;

- (void)generate:(int)keySize;
- (void)deletePrivateKey;

- (NSString *)encodedPublicKey;
- (NSString *)encodedPrivateKey;

- (NSString *)encrypt:(NSString *)message;

- (NSString *)encrypt64:(NSString *)message;

- (NSData *)_encrypt:(NSData *)message;

- (NSString *)decrypt:(NSString*)message algorithm:(SecKeyAlgorithm)algorithm;
- (NSString *)decrypt64:(NSString*)message algorithm:(SecKeyAlgorithm)algorithm;

- (NSString *)sign:(NSString *)message withAlgorithm:(NSString *)algorithm withEncodeOption: (NSDataBase64EncodingOptions)encodeOption;
- (BOOL)verify:(NSString *)signature withMessage:(NSString *)message withAlgorithm:(NSString *)verifyAlgorithm;

- (NSString *)sign64:(NSString *)b64message withAlgorithm:(NSString *)verifyAlgorithm;
- (BOOL)verify64:(NSString *)signature withMessage:(NSString *)b64message withAlgorithm:(NSString *)verifyAlgorithm;

- (NSString *)_sign:(NSData *)messageBytes;
- (BOOL)_verify:(NSData *)signatureBytes withMessage:(NSData *)messageBytes;

@end
