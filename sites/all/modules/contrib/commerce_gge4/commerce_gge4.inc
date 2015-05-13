<?php

class GGE4CustomerBillingAddress {
  public $name;  // could be single-line or multi-line name, I presume
  public $firstname;
  public $lastname;
  public $street1;
  public $street2;
  public $city;
  public $province;
  public $postalCode;
  public $billingPhone;
  public $countryDestinationID;
  public $email;
  public $ip;

  public function __construct($street1 = '', $street2 = '', $city = '', $province = '', $postalCode = '', $billingPhone = '', $countryDestinationID = 'us') {
    $this->street1              = $street1;
    $this->street2              = $street2;
    $this->city                 = $city;
    $this->province             = $province;
    $this->postalCode           = $postalCode;
    $this->billingPhone         = $billingPhone;
    $this->countryDestinationID = $countryDestinationID;
  }
}

class GGE4Card {
  public $cardNumber;
  public $expirationMonth;
  public $expirationYear;
  public $CVV;

  public function __construct($cardNumber = '', $expirationMonth = '', $expirationYear = '',  $CVV = '') {
    $this->cardNumber = $cardNumber;
    $this->expirationMonth = str_pad($expirationMonth, 2, "0", STR_PAD_LEFT); //2-digit month
    $this->expirationYear = substr($expirationYear, -2); //2-digit year
    $this->CVV = $CVV;
  }

  public function toArray() {
    return array(
      'Card_Number' => $this->cardNumber,
      'Expiry_Date' => $this->expirationMonth . $this->expirationYear,
      'CVV'         => $this->CVV,
    );
  }
}

class GGE4 {
  public $url;
  public $userName;
  public $secureAuthResult;
  public $ecommerceFlag;
  public $XID;
  public $exactID;
  public $CAVV;
  public $password;
  public $CAVVAlgorithm;
  public $transactionType;
  public $referenceNo;
  public $customerRef;
  public $reference3;
  public $clientIP;
  public $clientEmail;
  public $language;
  public $creditCard; // for cardnumber, expiry date, etc.
  public $billingAddress;
  public $track1;
  public $track2;
  public $authorizationNum;
  public $transactionTag;
  public $dollarAmount;
  public $verificationStr1;
  public $verificationStr2;
  public $CVDPresenceInd;
  public $secureAuthRequired;
  public $currency;
  public $partialRedemption;
  public $tax1Amount;
  public $tax1Number;
  public $tax2Amount;
  public $tax2Number;
  public $surchargeAmount;
  public $PAN;
  public $lineItems;



  public function __construct(
    $userName = '',
    $exactID = '', 
    $password = '', 
    $transactionType = '00', 
    $url='https://api.demo.globalgatewaye4.firstdata.com/transaction/v8/service.wsdl', 
    $creditCard = '',//new GGE4Card(), 
    $billingAddress = '',//new GGE4CustomerBillingAddress(), 
    $language = 'en'
  ) 
  { // construct it with at least the store-specific API info?
    $this->userName = $userName;
    $this->exactID = $exactID;
    $this->password = $password;
    $this->transactionType = $transactionType;
    $this->url = $url;
    $this->creditCard = $creditCard; // for cardnumber, expiry date, etc.
    $this->billingAddress = $billingAddress;
    $this->language = $language;
    $this->secureAuthResult = '';
    $this->ecommerceFlag = '';
    $this->XID = '';
    $this->CAVV = '';
    $this->CAVVAlgorithm = '';
    $this->referenceNo = '';
    $this->customerRef = '';
    $this->reference3 = '';
    $this->clientIP = '';
    $this->clientEmail = '';
    $this->track1 = '';
    $this->track2 = '';
    $this->authorizationNum = '';
    $this->transactionTag = '';
    $this->dollarAmount = '';
    $this->verificationStr1 = '';
    $this->verificationStr2 = '';
    $this->CVDPresenceInd = '';
    $this->secureAuthRequired = '';
    $this->currency = '';
    $this->partialRedemption = '';
    $this->tax1Amount = '';
    $this->tax1Number = '';
    $this->tax2Amount = '';
    $this->tax2Number = '';
    $this->surchargeAmount = '';
    $this->PAN = '';
    $this->lineItems = array();
  }

  public function authorizeAndCapture() {
    $this->response = $this->gge4Call('POST');
  }

  protected function gge4Call($method = 'POST') {

    $params = json_encode($this->toArrayForJson());
    $headers = array(
      "Content-Type" => "application/json",
      "charset" => "utf-8",
    );

    return drupal_http_request(
      $this->url,
      array(
        "method" => $method,
        "headers" => $headers,
        "data" => $params
      )
    );

  }

  public function toArray() {
    return array(
      "User_Name"=>$this->userName,
      "Secure_AuthResult"=>$this->secureAuthResult,
      "Ecommerce_Flag"=>$this->ecommerceFlag,
      "XID"=>$this->XID,
      "ExactID"=>$this->exactID,            //Payment Gateway
      "CAVV"=>$this->CAVV,
      "Password"=>$this->password,                       //Gateway Password
      "CAVV_Algorithm"=>$this->CAVVAlgorithm,
      "Transaction_Type"=>$this->transactionType,//Transaction Code I.E. Purchase="00" Pre-Authorization="01" etc.
      "Reference_No"=>$this->referenceNo,
      "Customer_Ref"=>$this->customerRef,
      "Reference_3"=>$this->reference3,
      "Client_IP"=>$this->clientIP,                              //This value is only used for fraud investigation.
      "Client_Email"=>$this->clientEmail,      //This value is only used for fraud investigation.
      "Language"=>$this->language,        //English="en" French="fr"
      "Card_Number"=>$this->creditCard->cardNumber,       //For Testing, Use Test#s VISA="4111111111111111" MasterCard="5500000000000004" etc.
      "Expiry_Date"=>$this->creditCard->expirationMonth . $this->creditCard->expirationYear,//This value should be in the format MMYY.
      "CardHoldersName"=>$this->billingAddress->name,
      "Track1"=>$this->track1,
      "Track2"=>$this->track2,
      "Authorization_Num"=>$this->authorizationNum,
      "Transaction_Tag"=>$this->transactionTag,
      "DollarAmount"=>$this->dollarAmount,
      "VerificationStr1"=>$this->verificationStr1,
      "VerificationStr2"=>$this->creditCard->CVV,
      "CVD_Presence_Ind"=>($this->creditCard->CVV === '' ? '0' : '1'),
      "Secure_AuthRequired"=>$this->secureAuthRequired,
      "Currency"=>$this->currency,
      "PartialRedemption"=>$this->partialRedemption,

      // Level 2 fields
      "ZipCode"=>$this->billingAddress->postalCode,
      "Tax1Amount"=>$this->tax1Amount,
      "Tax1Number"=>$this->tax1Number,
      "Tax2Amount"=>$this->tax2Amount,
      "Tax2Number"=>$this->tax2Number,

      "SurchargeAmount"=>$this->surchargeAmount, //Used for debit transactions only
      "PAN"=>$this->PAN,              //Used for debit transactions only
    );
  }

  public function toArrayForJson() {
    return array(
      "User_Name"=>$this->userName,
      "Secure_AuthResult"=>$this->secureAuthResult,
      "Ecommerce_Flag"=>$this->ecommerceFlag,
      "XID"=>$this->XID,
      "gateway_id"=>$this->exactID,            //Payment Gateway
      "CAVV"=>$this->CAVV,
      "password"=>$this->password,                       //Gateway Password
      "CAVV_Algorithm"=>$this->CAVVAlgorithm,
      "transaction_type"=>$this->transactionType,//Transaction Code I.E. Purchase="00" Pre-Authorization="01" etc.
      "Reference_No"=>$this->referenceNo,
      "Customer_Ref"=>$this->customerRef,
      "Reference_3"=>$this->reference3,
      "Client_IP"=>$this->clientIP,                              //This value is only used for fraud investigation.
      "Client_Email"=>$this->clientEmail,      //This value is only used for fraud investigation.
      "Language"=>$this->language,        //English="en" French="fr"
      "cc_number"=>$this->creditCard->cardNumber,       //For Testing, Use Test#s VISA="4111111111111111" MasterCard="5500000000000004" etc.
      "cc_expiry"=>$this->creditCard->expirationMonth . $this->creditCard->expirationYear,//This value should be in the format MMYY.
      "cardholder_name"=>$this->billingAddress->name,
      "Track1"=>$this->track1,
      "Track2"=>$this->track2,
      "authorization_num"=>$this->authorizationNum,
      "transaction_tag"=>$this->transactionTag,
      "amount"=>$this->dollarAmount,
      "cc_verification_str1"=>$this->verificationStr1,
      "cc_verification_str2"=>$this->creditCard->CVV,
      "CVD_Presence_Ind"=>($this->creditCard->CVV === '' ? '0' : '1'),
      "Secure_AuthRequired"=>$this->secureAuthRequired,
      "Currency"=>$this->currency,
      "PartialRedemption"=>$this->partialRedemption,

      // Level 2 fields
      "ZipCode"=>$this->billingAddress->postalCode,
      "Tax1Amount"=>$this->tax1Amount,
      "Tax1Number"=>$this->tax1Number,
      "Tax2Amount"=>$this->tax2Amount,
      "Tax2Number"=>$this->tax2Number,

      "SurchargeAmount"=>$this->surchargeAmount, //Used for debit transactions only
      "PAN"=>$this->PAN,              //Used for debit transactions only
    );
  }

}