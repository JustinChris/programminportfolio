#include <stdio.h>

int main() {
	long long int totalDrinks, bagCapacity;
	scanf("%lld %lld",&totalDrinks,&bagCapacity);
	long long int storeDrinks[totalDrinks];
	for (int i = 0; i < totalDrinks; i++) {
		scanf("%lld",&storeDrinks[i]);
	}
	long long int totalWeight = 0;
	long long int globalWeight = 0;
	for (int i = 0; i < totalDrinks; i++) {
		for (int j = 0; j < totalDrinks; j++) {
			if (i == j) {
				continue;
			}else {
				totalWeight = storeDrinks[i] + storeDrinks[j];
				if (totalWeight <= bagCapacity && totalWeight > globalWeight) {
					globalWeight = totalWeight;
				}else {
					totalWeight = 0;
				}
			}
		}
	}
	if (globalWeight == 0) {
		printf("-1\n");
	}else {
		printf("%d\n",globalWeight);
	}
	
	
	return 0;
}
