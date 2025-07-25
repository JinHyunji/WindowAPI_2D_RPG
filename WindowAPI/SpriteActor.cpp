#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"
#include "SceneManager.h"

SpriteActor::SpriteActor()
{
}

SpriteActor::~SpriteActor()
{
}

void SpriteActor::BeginPlay()
{
	Super::BeginPlay();

}

void SpriteActor::Tick()
{
	Super::Tick();

}

void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_sprite == nullptr) return;

	Vec2Int size = _sprite->GetSize();

	Vec2 cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();

	::BitBlt(hdc,
		// Dest
		(int32)_pos.x - size.x / 2 - ((int32)cameraPos.x - GWinSizeX / 2), // 시작 x좌표
		(int32)_pos.y - size.y / 2 - ((int32)cameraPos.y - GWinSizeY / 2), // 시작 y좌표
		size.x,
		size.y,
		// Source
		_sprite->GetDC(),
		_sprite->GetPos().x, // Sprite의 시작 x위치
		_sprite->GetPos().y, // Sprite의 시작 y위치
		SRCCOPY);
}
