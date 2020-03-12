// Fill out your copyright notice in the Description page of Project Settings.


#include "PtLoadUserWidget.h"
#include "CircularThrobber.h"
#include "TextBlock.h"
#include "Button.h"
#include "PtGameInstance.h"

/** �ؼ�������ɳ�ʼ������ */
bool UPtLoadUserWidget::Initialize()
{
	if (!Super::Initialize())return false;

	//��ʼ��������
	CircularThrobber = Cast<UCircularThrobber>(GetWidgetFromName(TEXT("CircularThrobber_Load")));
	//��ʼ�������ı�
	LoadingText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_Load")));
	//��ʼ��������ť
	NextButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Next")));

	return true;
}

void UPtLoadUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	if (PtGameInstance)
	{
		if (PtGameInstance->GetLoadStatus())
		{
			SetEndLoad();
		}
	}
	else
	{
		PtGameInstance = Cast<UPTGameInstance>(GetGameInstance());
	}
}

void UPtLoadUserWidget::SetStartLoad()
{
	this->CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	this->LoadingText->SetVisibility(ESlateVisibility::Visible);
	this->NextButton->SetVisibility(ESlateVisibility::Hidden);
}

void UPtLoadUserWidget::SetEndLoad()
{
	this->CircularThrobber->SetVisibility(ESlateVisibility::Hidden);
	this->LoadingText->SetVisibility(ESlateVisibility::Hidden);
	this->NextButton->SetVisibility(ESlateVisibility::Visible);
}
