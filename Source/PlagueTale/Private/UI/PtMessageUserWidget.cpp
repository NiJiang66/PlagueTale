// Fill out your copyright notice in the Description page of Project Settings.


#include "PtMessageUserWidget.h"
#include "TextBlock.h"
#include "Button.h"


bool UPtMessageUserWidget::Initialize()
{
	if (!Super::Initialize())return false;

	//�����ı���
	MsgBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Message")));

	//�����رհ�ť
	CloseBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_MessageClose")));
	//���ùرհ�ť�ûص�
	CloseBtn->OnClicked.AddDynamic(this, &UPtMessageUserWidget::ClosButtonOnClickedEvent);

	return true;
}

/* ���ùرհ�ť�¼�*/
void UPtMessageUserWidget::ClosButtonOnClickedEvent()
{
	this->SetVisibility(ESlateVisibility::Hidden);
}
