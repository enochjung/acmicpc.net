#include <cstdio>

struct st
{
	int y;
	char s[60];
};

int q, s, e;
st a[25] = {
	{1967, "DavidBowie"},
	{1969, "SpaceOddity"},
	{1970, "TheManWhoSoldTheWorld"},
	{1971, "HunkyDory"},
	{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
	{1973, "AladdinSane"},
	{1973, "PinUps"},
	{1974, "DiamondDogs"},
	{1975, "YoungAmericans"},
	{1976, "StationToStation"},
	{1977, "Low"},
	{1977, "Heroes"},
	{1979, "Lodger"},
	{1980, "ScaryMonstersAndSuperCreeps"},
	{1983, "LetsDance"},
	{1984, "Tonight"},
	{1987, "NeverLetMeDown"},
	{1993, "BlackTieWhiteNoise"},
	{1995, "1.Outside"},
	{1997, "Earthling"},
	{1999, "Hours"},
	{2002, "Heathen"},
	{2003, "Reality"},
	{2013, "TheNextDay"},
	{2016, "BlackStar"}
};

int main()
{
	for(scanf("%d",&q); q--;)
	{
		scanf("%d %d", &s, &e);

		int cnt = 0;
		for(int i=0; i<25; ++i)
			if(s<=a[i].y && a[i].y<=e)
				++cnt;

		printf("%d\n", cnt);
		for(int i=0; i<25; ++i)
			if(s<=a[i].y && a[i].y<=e)
				printf("%d %s\n", a[i].y, a[i].s);
	}

	return 0;
}
