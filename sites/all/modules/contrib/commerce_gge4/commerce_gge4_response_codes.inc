<?php

/**
 * @file
 * Returns description of response codes returned from a GGE4 request
 */

/**
 * First Data Response Codes
 *
 * The following list reflects all currently defined First Data response reason codes. Many of these codes will never be returned in your output.
 *
 * For the most common codes returned by First Data , the list includes an action field that suggests the best probable course of action to take based on the code returned. If you are receiving codes not listed here, please contact your Account Manager. The following KEY describes the Column Headings and the values appearing in the columns.
 *
 * Note: Not all codes will be received on an authorization. Some codes are for deposit/conditionals only
 *
 * Description
 * Type
 * S = Successful Response Codes
 *
 * R = Reject Response Codes
 *
 * D = Decline Response Codes
 *
 * Code
 * 3‐digit response code
 *
 * Name
 * Description of the response code
 *
 * Action
 * Resend = Send this transaction back at any time
 *
 * Wait = Wait 2‐3 days before sending back, or try to resolve with your customer
 *
 * Cust. = Try to resolve with customer, or get an alternate method of payment
 *
 * Fix = There is an invalid field being sent Fix and resend
 *
 * N/A = Not applicable
 *
 * Voice = Perform a voice authorization per First Data instructions
 *
 * Call = Call First Data
 */

function commerce_gge4_response_code($code) {

  switch($code) {
    case '000':
      return '000 No Answer Resend  First Data received no answer from auth network';
    case '100':
      return 'Success: 100 Approved  N/A Successfully approved';
    case '101':
      return 'Success: 101 Validated N/A Account Passed edit checks';
    case '102':
      return 'Success: 102 Verified  N/A Account Passed external negative file';
    case '103':
      return 'Success: 103 Pre-Noted N/A Passed Pre-Note';
    case '104':
      return 'Success: 104 No Reason to Decline  N/A Successfully approved';
    case '105':
      return 'Success: 105 Received and Stored N/A Successfully approved';
    case '106':
      return 'Success: 106 Provided Auth N/A Successfully approved Note: Indicates customized code was used in processing';
    case '107':
      return 'Success: 107 Request Received  N/A Successfully approved Note: Indicates customized code was used in processing';
    case '108':
      return 'Success: 108 Approved for Activation N/A Successfully Activated';
    case '109':
      return 'Success: 109 Previously Processed Transaction  N/A Transaction was not re-authorized with the Debit Network because it was previously processed';
    case '110':
      return 'Success: 110 BIN Alert N/A Successfully approved Note: Indicates customized code was used in processing';
    case '111':
      return 'Success: 111 Approved for Partial  N/A Successfully approved Note: Indicates customized code was used in processing';
    case '164':
      return 'Success: 164 Conditional Approval  Wait  Conditional Approval - Hold shipping for 24 hours';
    case '201':
      return 'Rejected: 201 Invalid CC Number Cust  Bad check digit, length, or other credit card problem';
    case '202':
      return 'Rejected: 202 Bad Amount Nonnumeric Amount  If  Amount sent was zero, unreadable, over ceiling limit, or exceeds maximum allowable amount.';
    case '203':
      return 'Rejected: 203 Zero Amount Fix Amount sent was zero';
    case '204':
      return 'Rejected: 204 Other Error Fix Unidentifiable error';
    case '205':
      return 'Rejected: 205 Bad Total Auth Amount Fix The sum of the authorization amount from extended data information does not equal detail record authorization Amount. Amount sent was zero, unreadable, over ceiling limit, or exceeds Maximum allowable amount.';
    case '218':
      return 'Rejected: 218 Invalid SKU Number  Fix Non‐numeric value was sent';
    case '219':
      return 'Rejected: 219 Invalid Credit Plan Fix Non‐numeric value was sent';
    case '220':
      return 'Rejected: 220 Invalid Store Number  Fix Non‐numeric value was sent';
    case '225':
      return 'Rejected: 225 Invalid Field Data  Fix Data within transaction is incorrect';
    case '227':
      return 'Rejected: 227 Missing Companion Data  Fix Specific and relevant data within transaction is absent';
    case '229':
      return 'Rejected: 229 Percents do not total 100 Fix FPO monthly payments do not total 100 Note: FPO only';
    case '230':
      return 'Rejected: 230 Payments do not total 100 Fix FPO monthly payments do not total 100 Note: FPO only';
    case '231':
      return 'Rejected: 231 Invalid Division Number Fix Division number incorrect';
    case '233':
      return 'Rejected: 233 Does not match MOP  Fix Credit card number does not match method of payment type or invalid BIN';
    case '234':
      return 'Rejected: 234 Duplicate Order Number  Fix Unique to authorization recycle transactions. Order number already exists in system Note: Auth Recycle only';
    case '235':
      return 'Rejected: 235 FPO Locked  Resend  FPO change not allowed Note: FPO only';
    case '236':
      return 'Rejected: 236 Auth Recycle Host System Down Resend  Authorization recycle host system temporarily unavailable Note: Auth Recycle only';
    case '237':
      return 'Rejected: 237 FPO Not Approved  Call  Division does not participate in FPO. Contact your First Data Representative for information on getting set up for FPO Note: FPO only';
    case '238':
      return 'Rejected: 238 Invalid Currency  Fix Currency does not match First Data merchant setup for division';
    case '239':
      return 'Rejected: 239 Invalid MOP for Division  Fix Method of payment is invalid for the division';
    case '240':
      return 'Rejected: 240 Auth Amount for Division  Fix Used by FPO';
    case '241':
      return 'Rejected: 241 Illegal Action  Fix Invalid action attempted';
    case '243':
      return 'Rejected: 243 Invalid Purchase Level 3  Fix Data is inaccurate or missing, or the BIN is ineligible for P‐card';
    case '244':
      return 'Rejected: 244 Invalid Encryption Format Fix Invalid encryption flag. Data is Inaccurate.';
    case '245':
      return 'Rejected: 245 Missing or Invalid Secure Payment Data  Fix Visa or MasterCard authentication data not in appropriate Base 64 encoding format or data provided on A non‐e‐Commerce transaction.';
    case '246':
      return 'Rejected: 246 Merchant not MasterCard Secure code Enabled Call  Division does not participate in MasterCard Secure Code. Contact your First Data Representative for information on getting setup for MasterCard SecureCode.';
    case '247':
      return 'Rejected: 247 Check conversion Data Error Fix Proper data elements were not sent';
    case '248':
      return 'Rejected: 248 Blanks not passed in reserved field Fix Blanks not passed in Reserved Field';
    case '249':
      return 'Rejected: 249 Invalid (MCC) Fix Invalid Merchant Category (MCC) sent';
    case '251':
      return 'Rejected: 251 Invalid Start Date  Fix Incorrect start date or card may require an issue number, but a start date was submitted.';
    case '252':
      return 'Rejected: 252 Invalid Issue Number  Fix Issue number invalid for this BIN.';
    case '253':
      return 'Rejected: 253 Invalid Tran. Type  Fix If an “R” (Retail Indicator) is sent for a transaction with a MOTO Merchant Category Code (MCC)';
    case '257':
      return 'Rejected: 257 Missing Cust Service Phone  Fix Card was authorized, but AVS did not match. The 100 was overwritten with a 260 per the merchant’s request Note: Conditional deposits only';
    case '258':
      return 'Rejected: 258 Not Authorized to Send Record Call Division does not participate in Soft Merchant Descriptor.

Contact your First Data Representative for information on getting set up for Soft Merchant Descriptor.';
    case '260':
      return 'Declined: 260 Soft AVS  Cust. Authorization network could not reach the bank which issued the card';
    case '261':
      return 'Rejected: 261 Account Not Eligible For Division’s Setup N/A Account number not eligible for division’s Account Updater program setup';
    case '262':
      return 'Rejected: 262 Authorization Code Response Date Invalid  Fix Authorization code and/or response date are invalid. Note: MOP = MC, MD, VI only';
    case '263':
      return 'Rejected: 263 Partial Authorization Not Allowed or Partial Authorization Request Note Valid Fix Action code or division does not allow partial authorizations or partial authorization request is not valid.';
    case '264':
      return 'Rejected: 264 Duplicate Deposit Transaction N/A Transaction is a duplicate of a previously deposited transaction. Transaction will not be processed.';
    case '265':
      return 'Rejected: 265 Missing QHP Amount  Fix Missing QHP Amount';
    case '266':
      return 'Rejected: 266 Invalid QHP Amount  Fix QHP amount greater than transaction amount';
    case '274':
      return 'Rejected: 274 Transaction Not Supported N/A The requested transaction type is blocked from being used with this card.

Note:  This may be the result of either an association rule, or a merchant boarding option.';
    case '301':
      return 'Declined: 301 Issuer unavailable  Resend  Authorization network could not reach the bank which issued the card';
    case '302':
      return 'Declined: 302 Credit Floor  Wait  Insufficient funds';
    case '303':
      return 'Declined: 303 Processor Decline Cust. Generic decline – No other information is being provided by the Issuer';
    case '304':
      return 'Declined: 304 Not On File Cust. No card record, or invalid/nonexistent to account specified';
    case '305':
      return 'Declined: 305 Already Reversed  N/A Transaction previously reversed. Note: MOP = any Debit MOP, SV, MC, MD, VI only';
    case '306':
      return 'Declined: 306 Amount Mismatch Fix Requested reversal amount does not match original approved authorization amount. Note: MOP = MC, MD, VI only';
    case '307':
      return 'Declined: 307 Authorization Not Found Fix Transaction cannot be matched to an authorization that was stored in the database. Note: MOP = MC, MD, VI only';
    case '351':
      return 'Rejected: 351 TransArmor Service Unavailable  Resend  TransArmor Service temporarily unavailable.';
    case '352':
      return 'Declined: 352 Expired Lock  Cust. ValueLink - Lock on funds has expired.';
    case '353':
      return 'Rejected: 353 TransArmor Invalid Token or PAN Fix TransArmor Service encountered a problem converting the given Token or PAN with the given Token Type.';
    case '354':
      return 'Rejected: 354 TransArmor Invalid Result Cust  TransArmor Service encountered a problem with the resulting Token/PAN.';
    case '401':
      return 'Declined: 401 Call  Voice Issuer wants voice contact with cardholder';
    case '402':
      return 'Declined: 402 Default Call  Voice Decline';
    case '501':
      return 'Declined: 501 Pickup  Cust  Card Issuer wants card returned';
    case '502':
      return 'Declined: 502 Lost/Stolen Cust  Card reported as lost/stolen Note: Does not apply to American Express';
    case '503':
      return 'Declined: 503 Fraud/ Security Violation Cust  CID did not match Note: Discover only';
    case '505':
      return 'Declined: 505 Negative File Cust  On negative file';
    case '508':
      return 'Declined: 508 Excessive PIN try Cust  Allowable number of PIN tries exceeded';
    case '509':
      return 'Declined: 509 Over the limit  Cust  Exceeds withdrawal or activity amount limit';
    case '510':
      return 'Declined: 510 Over Limit Frequency  Cust  Exceeds withdrawal or activity count limit';
    case '519':
      return 'Declined: 519 On negative file  Cust  Account number appears on negative file';
    case '521':
      return 'Declined: 521 Insufficient funds  Cust  Insufficient funds/over credit limit';
    case '522':
      return 'Declined: 522 Card is expired Cust  Card has expired';
    case '524':
      return 'Declined: 524 Altered Data  Fix Altered Data\Magnetic stripe incorrect';
    case '530':
      return 'Declined: 530 Do Not Honor  Cust  Generic Decline – No other information is being provided by the issuer. Note: This is a hard decline for BML (will never pass with recycle attempts)';
    case '531':
      return 'Declined: 531 CVV2/VAK Failure  Cust  Issuer has declined auth request because CVV2 or VAK failed';
    case '534':
      return 'Declined: 534 Do Not Honor - High Fraud Cust  The transaction has failed PayPal or Google Checkout risk models';
    case '570':
      return 'Declined: 570 Stop payment order one time recurring/ installment  Fix Cardholder has requested this one recurring/installment payment be stopped.';
    case '571':
      return 'Declined: 571 Revocation of Authorization for All Recurring / Installments  Cust  Cardholder has requested all recurring/installment payments be stopped';
    case '572':
      return 'Declined: 572 Revocation of All Authorizations – Closed Account Cust  Cardholder has requested that all authorizations be stopped for this account due to closed account. Note: Visa only';
    case '580':
      return 'Declined: 580 Account previously activated  Cust  Account previously activated';
    case '581':
      return 'Declined: 581 Unable to void  Fix Unable to void';
    case '582':
      return 'Declined: 582 Block activation failed Fix Reserved for Future Use';
    case '583':
      return 'Declined: 583 Block Activation Failed Fix Reserved for Future Use';
    case '584':
      return 'Declined: 584 Issuance Does Not Meet Minimum Amount Fix Issuance does not meet minimum amount';
    case '585':
      return 'Declined: 585 No Original Authorization Found N/A No original authorization found';
    case '586':
      return 'Declined: 586 Outstanding Authorization, Funds on Hold  N/A Outstanding Authorization, funds on hold';
    case '587':
      return 'Declined: 587 Activation Amount Incorrect Fix Activation amount incorrect';
    case '588':
      return 'Declined: 588 Block Activation Failed Fix Reserved for Future Use';
    case '589':
      return 'Declined: 589 CVD Value Failure Cust  Magnetic stripe CVD value failure';
    case '590':
      return 'Declined: 590 Maximum Redemption Limit Met  Cust  Maximum redemption limit met';
    case '591':
      return 'Declined: 591 Invalid CC Number Cust  Bad check digit, length or other credit card problem. Issuer generated';
    case '592':
      return 'Declined: 592 Bad Amount  Fix Amount sent was zero or unreadable. Issuer generated';
    case '594':
      return 'Declined: 594 Other Error Fix Unidentifiable error. Issuer generated';
    case '595':
      return 'Declined: 595 New Card Issued Cust  New Card Issued';
    case '596':
      return 'Declined: 596 Suspected Fraud Cust  Issuer has flagged account as suspected fraud';
    case '599':
      return 'Declined: 599 Refund Not Allowed  N/A Refund Not Allowed';
    case '602':
      return 'Declined: 602 Invalid Institution Code  Fix Card is bad, but passes MOD 10 check digit routine, wrong BIN';
    case '603':
      return 'Declined: 603 Invalid Institution Cust  Institution not valid (i.e. possible merger)';
    case '605':
      return 'Declined: 605 Invalid Expiration Date Cust  Card has expired or bad date sent. Confirm proper date';
    case '606':
      return 'Declined: 606 Invalid Transaction Type  Cust  Issuer does not allow this type of transaction';
    case '607':
      return 'Declined: 607 Invalid Amount  Fix Amount not accepted by network';
    case '610':
      return 'Declined: 610 BIN Block Cust  Merchant has requested First Data not process credit cards with this BIN';
    case '704':
      return 'Success: 704 FPO Accepted  N/A Stored in FPO database';
    case '740':
      return 'Rejected: 740 Match Failed  Fix Unable to validate the debit.

Authorization Record - based on amount, action code, and MOP (Batch response reason code for Debit Only)';
    case '741':
      return 'Rejected/Declined: 741 Validation Failed Fix Unable to validate the Debit

Authorization Record - based on amount, action code, and MOP (Batch response reason code for Debit Only)';
    case '750':
      return 'Rejected/Declined: 750 Invalid Transit Routing Number  Fix EC - ABA transit routing number is invalid, failed check digit';
    case '751':
      return 'Rejected/Declined: 751 Transit Routing Number Unknown  Fix Transit routing number not on list of current acceptable numbers.';
    case '752':
      return 'Rejected: 752 Missing Name  Fix Pertains to deposit transactions only';
    case '753':
      return 'Rejected: 753 Invalid Account Type  Fix Pertains to deposit transactions only';
    case '754':
      return 'Rejected/Declined: 754 Account Closed  Cust  Bank account has been closed For PayPal and GoogleCheckout – the customer’s account was closed / restricted';
    case '802':
      return 'Declined: 802 Positive ID Voice Issuer requires further information';
    case '806':
      return 'Declined: 806 Restraint Cust  Card has been restricted';
    case '811':
      return 'Declined: 811 Invalid Security Code Fix American Express CID is incorrect';
    case '813':
      return 'Declined: 813 Invalid PIN Cust  PIN for online debit transactions is incorrect';
    case '825':
      return 'Declined: 825 No Account  Cust  Account does not exist';
    case '833':
      return 'Declined: 833 Invalid Merchant  Fix Service Established (SE) number is incorrect, closed or Issuer does not allow this type of transaction';
    case '834':
      return 'Rejected: 834 Unauthorized User Fix Method of payment is invalid for the division';
    case '902':
      return 'Declined: 902 Process Unavailable Resend/ Call/ Cust. System error/malfunction with Issuer For Debit – The link is down or setup issue; contact your First Data Representative.';
    case '903':
      return 'Declined: 903 Invalid Expiration  Cust  Invalid or expired expiration date';
    case '904':
      return 'Declined: 904 Invalid Effective Cust./ Resend Card not active';
  }

  return '-';
}
