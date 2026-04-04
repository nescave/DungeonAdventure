#pragma once

namespace DACollisionProfile
{
	const FName NoCollision = FName(TEXT("NoCollision"));
	const FName Character = FName(TEXT("CharacterMesh"));
	const FName Enemy = FName(TEXT("Enemy"));
	const FName Weapon = FName(TEXT("Weapon"));
}

namespace DATraceChannel
{
	constexpr ECollisionChannel Interactions = ECC_GameTraceChannel1;
	constexpr ECollisionChannel PlayerHitBox = ECC_GameTraceChannel2;
	constexpr ECollisionChannel EnemyHitBox = ECC_GameTraceChannel3;
	constexpr ECollisionChannel Enemy = ECC_GameTraceChannel4;
}