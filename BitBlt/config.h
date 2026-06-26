int sw = GetSystemMetrics(0);
int sh = GetSystemMetrics(1);

static DWORD xs;

void SeedXorshift32(DWORD dwSeed);
DWORD xorshift32();
static DWORD GetSeed();
