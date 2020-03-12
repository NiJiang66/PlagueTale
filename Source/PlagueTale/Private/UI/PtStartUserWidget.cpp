// Fill out your copyright notice in the Description page of Project Settings.


#include "PtStartUserWidget.h"
#include "Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TextBlock.h"

#include "Engine/KBEMain.h"


/** �ؼ�������ɺ��ʼ������ */
bool UPtStartUserWidget::Initialize()
{
	if (!Super::Initialize())return false;

	//��ʼ����ʼ��Ϸ��ť
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Start")));
	//��ʼ��ע���˺Ű�ť
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	//��ʼ���˳���Ϸ��ť
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	//��ʼ���汾��Ϣ
	clientVersionLabel->SetText(FText::FromString("client version:" + UKBEMain::getClientVersion()));
	clientScriptVersionLabel->SetText(FText::FromString("client script version:" + UKBEMain::getClientScriptVersion()));
	serverVerstionLabel->SetText(FText::FromString("server version:" + UKBEMain::getServerVersion()));
	serverScriptVersionLabel->SetText(FText::FromString("server script version:" + UKBEMain::getServerScriptVersion()));

	//�˳���Ϸ��ť����¼�
	QuitBtn->OnClicked.AddDynamic(this, &UPtStartUserWidget::QuitBtnOnClickedEvent);

	return true;
}

/** �˳���Ϸ��ť����¼� */
void UPtStartUserWidget::QuitBtnOnClickedEvent()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, true);
}