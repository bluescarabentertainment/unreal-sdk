// Copyright (c) 2021 LootLocker

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LootLockerConfig.h"
#include "LootLockerHttpClient.h"
#include "GameAPI/LootLockerPersistentStorageRequestHandler.h"
#include "LootLockerAssetsRequestHandler.generated.h"

USTRUCT(BlueprintType)
struct FLootLockerDefaultLoadouts {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool skier = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool snowboarder = false;
};
USTRUCT(BlueprintType)
struct FLootLockerPsn {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString entitlement_id;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 service_label = 0;
};
USTRUCT(BlueprintType)
struct FLootLockerExternalIdentifiers {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerPsn psn;
};
USTRUCT(BlueprintType)
struct FLootLockerFile {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString url;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FString> tags;
};
USTRUCT(BlueprintType)
struct FLootLockerFilter {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString value;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
};
USTRUCT(BlueprintType)
struct FLootLockerRarity {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString short_name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString color;
};
USTRUCT(BlueprintType)
struct FLootLockerLinks {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString thumbnail;
};
USTRUCT(BlueprintType)
struct FLootLockerRentalOption {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 id = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 duration = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 price = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString sales_price;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerLinks links;
};
USTRUCT(BlueprintType)
struct FLootLockerBoneOverrides 
{
    GENERATED_BODY()
};
//USTRUCT(BlueprintType)
//struct FProperty {
//    GENERATED_BODY()
//    FString material_path;
//    FString binding_path;
//    int bone_id;
//    FLootLockerBoneOverrides bone_overrides;
//};

USTRUCT(BlueprintType)
struct FLootLockerVariation {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 id = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString primary_color;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString secondary_color;
  //  TArray<FProperty> properties;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerLinks links;
};

USTRUCT(BlueprintType)
struct FLootLockerAssetCandidate
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int created_by_player_id = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString created_by_player_uid;
};

USTRUCT(BlueprintType)
struct FLootLockerAsset
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 id = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool active = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString type;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 price = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString sales_price;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString display_price;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString shop_thumbnail;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString context;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool detachable = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool purchasable = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool initially_purchasable = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString updated;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString marked_new;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 default_variation_id = 0;
  //  UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
  //  FLootLockerDefaultLoadouts default_loadouts;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString description;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool featured = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool context_locked = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString unlocks_context;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerRarity rarity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool popular = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int32 popularity_score = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool unique_instance = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerExternalIdentifiers external_identifiers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerVariation> variations;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerFilter> filters;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerRentalOption> rental_options;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerFile> files;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FString> data_entities;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerLinks links;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerPersistentStorageItem> storage;
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
//    TArray<FString> package_contents; //TODO: check output
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FLootLockerAssetCandidate asset_candidate;
};

USTRUCT(BlueprintType)
struct FLootLockerContext {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int id = 0;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString friendly_name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool detachable = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    bool user_facing = false;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    int dependent_asset_id = 0;
};

USTRUCT(BlueprintType)
struct FLootLockerGetContextResponse : public FLootLockerResponse
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerContext> contexts;
};

USTRUCT(BlueprintType)
struct FLootLockerGetAssetsResponse : public FLootLockerResponse
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerAsset> assets;
};

UENUM(BlueprintType)
enum class ELootLockerAssetFilter : uint8
{
    None = 0,
    Purchasable = 1,
    NonPurchasable = 2,
    Rentable = 3,
    NonRentable = 4,
    Popular = 5,
    UnPopular = 6
};

USTRUCT(BlueprintType)
struct FLootLockerAssetBoneParameters {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString rotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString position;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString boneName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString flags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString mass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString binding;
};

USTRUCT(BlueprintType)
struct FLootLockerAssetBone {
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString id;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    FString name;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerAssetBoneParameters> parameters;
};

USTRUCT(BlueprintType)
struct FLootLockerGetAssetBonesResponse : public FLootLockerResponse
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<FLootLockerAssetBone> AssetBones;
};

USTRUCT(BlueprintType)
struct FLootLockerGetFavouriteAssetIndicesResponse : public FLootLockerResponse
{
    GENERATED_BODY()
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLocker")
    TArray<int> favourites;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FContextDelegateBP, FLootLockerGetContextResponse, ContextsResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAssetsResponseDelegateBP, FLootLockerGetAssetsResponse, AssetsResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAssetBonesResponseDelegateBP, FLootLockerGetAssetBonesResponse, AssetBonesResponse);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGetFavouriteAssetIndicesResponseDelegateBP, FLootLockerGetFavouriteAssetIndicesResponse, FavouriteAssetIndicesResponse);
DECLARE_DELEGATE_OneParam(FContextDelegate, FLootLockerGetContextResponse);
DECLARE_DELEGATE_OneParam(FAssetsResponseDelegate, FLootLockerGetAssetsResponse);
DECLARE_DELEGATE_OneParam(FAssetBonesResponseDelegate, FLootLockerGetAssetBonesResponse);
DECLARE_DELEGATE_OneParam(FGetFavouriteAssetIndicesResponseDelegate, FLootLockerGetFavouriteAssetIndicesResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERSDK_API ULootLockerAssetsRequestHandler : public UObject
{
    GENERATED_BODY()
public:
    static void GetContexts(const FContextDelegateBP& OnCompletedRequestBP = FContextDelegateBP(), const FContextDelegate& OnCompletedRequest = FContextDelegate());
    
    static void GetAssets(int StartFromIndex, int ItemsCount, ELootLockerAssetFilter AssetFilter, int Context, bool IncludeUGC, const FAssetsResponseDelegateBP& OnCompletedRequestBP = FAssetsResponseDelegateBP(), const FAssetsResponseDelegate& OnCompletedRequest = FAssetsResponseDelegate());
    
    static void GetAssetsByIds(const TArray<int>& AssetIds, const FAssetsResponseDelegateBP& OnCompletedRequestBP = FAssetsResponseDelegateBP(), const FAssetsResponseDelegate& OnCompletedRequest = FAssetsResponseDelegate());

    static void GetAssetBones(const FAssetBonesResponseDelegateBP& OnCompletedRequestBP = FAssetBonesResponseDelegateBP(), const FAssetBonesResponseDelegate& OnCompletedRequest = FAssetBonesResponseDelegate());
    
    static void GetFavouriteAssetIndices(const FGetFavouriteAssetIndicesResponseDelegateBP& OnCompletedRequestBP = FGetFavouriteAssetIndicesResponseDelegateBP(), const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest = FGetFavouriteAssetIndicesResponseDelegate());
    
    static void AddAssetToFavourites(int AssetId, const FGetFavouriteAssetIndicesResponseDelegateBP& OnCompletedRequestBP = FGetFavouriteAssetIndicesResponseDelegateBP(), const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest = FGetFavouriteAssetIndicesResponseDelegate());
    
    static void RemoveAssetFromFavourites(int AssetId, const FGetFavouriteAssetIndicesResponseDelegateBP& OnCompletedRequestBP = FGetFavouriteAssetIndicesResponseDelegateBP(), const FGetFavouriteAssetIndicesResponseDelegate& OnCompletedRequest = FGetFavouriteAssetIndicesResponseDelegate());
    
public:
    ULootLockerAssetsRequestHandler();

    static ULootLockerHttpClient* HttpClient;
};
