#include <global.h>

LL_AUTO_STATIC_HOOK(
	NoFarmDestroy,
	HookPriority::Normal,
	"?transformOnFall@FarmBlock@@UEBAXAEAVBlockSource@@AEBVBlockPos@@PEAVActor@@M@Z",
	void,
	void* __this, void* a2,
	void* a3, void* a4, float a5
) {
	if (settings::NoFarmDestroy) {
		return;
	}
	return origin(__this, a2, a3, a4, a5);
}
