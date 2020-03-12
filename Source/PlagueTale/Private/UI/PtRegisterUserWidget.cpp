// Fill out your copyright notice in the Description page of Project Settings.


#include "PtRegisterUserWidget.h"
#include "Button.h"
#include "TextBlock.h"
#include "EditableTextBox.h"
#include "CircularThrobber.h"
#include "PtMessageUserWidget.h"

#include "JsonWriter.h"
#include "JsonObject.h"
#include "JsonReader.h"
#include "JsonSerializer.h"
#include "CondensedJsonPrintPolicy.h"
#include "Kismet/GameplayStatics.h"

#include "Engine/KBEMain.h"
#include "PtStartGameMode.h"


/** �жϿؼ������Ƿ���سɹ� */
bool UPtRegisterUserWidget::Initialize()
{
	if (!Super::Initialize())return false;

	/* ��ʼ�����ذ�ť*/
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	/* ��ʼ���ǳ������*/
	NicknameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Nickname")));
	/* ��ʼ�����������*/
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Password")));
	/* ��ʼ���ٴ����������*/
	RePasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Repassword")));
	/* ��ʼ��ע�ᰴť*/
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	/* ��ʼ��LoadingЧ��*/
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Loading")));
	/* ��ʼ��Message*/
	MessageUserWidget = Cast<UPtMessageUserWidget>(GetWidgetFromName(TEXT("Message_Box")));

	//ע�ᰴť����¼��ص�
	RegisterBtn->OnClicked.AddDynamic(this, &UPtRegisterUserWidget::OnRegisterBtnOnClicked);

	return true;
}

/** ע�ᰴť����¼� */
void UPtRegisterUserWidget::OnRegisterBtnOnClicked()
{
	//��ȡ�ǳ�
	FString Nickname = NicknameInput->GetText().ToString();
	//��ȡ����
	FString Password = PasswordInput->GetText().ToString();
	//��ȡȷ������
	FString RePassword = RePasswordInput->GetText().ToString();

	//�ǳƵĳ����Ƿ�Ϸ�2-6
	if (Nickname.Len() < 2 || Nickname.Len() > 6)
	{
		//�ǳƳ����Ƿ�Ϸ�
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString("NickName Is Not Right"));
		return;
	}
	//��������������Ƿ�һ��
	if (!Password.Equals(RePassword))
	{
		//�����Ƿ�һ��
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString("Second Password Is Not Same"));
		return;
	}

	//�������������������
	TArray<uint8> LoginData;
	FString ProjectName("PlagueTale");
	for (int i = 0; i < ProjectName.Len(); ++i) {
		LoginData.Push((uint8)ProjectName[i]);
	}		

	APtStartGameMode* SGM = Cast<APtStartGameMode>(UGameplayStatics::GetGameMode(this));
	if (SGM) {
		SGM->KBEMain->createAccount(Nickname, Password, LoginData);
	}

	//��ʾ���ؿ�
	//CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	//����ע�ᰴť������
	RegisterBtn->SetIsEnabled(false);
	//�����˺�ע��
	//AccountRegisterFromServer(Nickname, Password);
}

/** �˺�ע�᷽�� */
void UPtRegisterUserWidget::AccountRegisterFromServer(FString&Nickname, FString&Password)
{
	//����Ҫ�ύ��Json�ַ���
	FString RegisterInfo;
	//��������Jsonд����
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	//��ʼд������
	JsonWriter->WriteObjectStart();
	//д���ǳƵ�Json
	JsonWriter->WriteValue("nickname", Nickname);
	//д�����뵽Json
	JsonWriter->WriteValue("password", Password);
	//�ر�Jsonд��
	JsonWriter->WriteObjectEnd();
	//�ر�Jsonд����
	JsonWriter->Close();

	//����HTTP����
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	//��������ʽ
	HttpRequest->SetVerb("POST");
	//��������ͷ
	HttpRequest->SetHeader("Content-Type", "application/json;charset=utf-8");
	//���������url
	HttpRequest->SetURL("http://www.xxx.com:7900/user/register-user");
	//�����ϴ�������
	HttpRequest->SetContentAsString(RegisterInfo);
	//��������ɹ���ί�з���
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UPtRegisterUserWidget::RequestComplete);
	//���������
	HttpRequest->ProcessRequest();
}

/** ������Ӧ���� */
void UPtRegisterUserWidget::RequestComplete(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	//���ؼ��ؿ�
	CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	//����ע�ᰴť����
	RegisterBtn->SetIsEnabled(true);
	//�ж���Ӧ״̬�Ƿ�����
	if (!ResponsePtr || !EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		return;
	}
	//��ȡ���ص�ֵ
	FString Data = ResponsePtr->GetContentAsString();
	//����һ��Json����
	TSharedPtr<FJsonObject> JsonObject;
	//����Json������
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	//Json�����л�
	bool bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	//�ж��Ƿ�����ɹ�
	if (bIsParse)
	{
		//�������������ص���Ϣ
		FString Msg = JsonObject->GetStringField("msg");
		//��ʾ��ʾ��Ϣ
		MessageUserWidget->SetVisibility(ESlateVisibility::Visible);
		MessageUserWidget->MsgBlock->SetText(FText::FromString(Msg));
	}
}
