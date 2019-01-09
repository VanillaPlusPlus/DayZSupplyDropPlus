# DayZSupplyDropPlus
A complete server side airdrop script for DayZ Standalone.

# Installation:
- Download the projects zip file. [Here](https://github.com/VanillaPlusPlus/SupplyDropPlus/archive/master.zip)
- Uncompress the Zip folder, and move the SupplyDropPlus folder into the same location where init.c is located.

**Example location:** ```/mpmission/dayzOffline.chernarusplus/```

**Note: If you are using any other mission name other than** ```dayzOffline.chernarusplus```**, you will have to change the includes inside of SupplyDropPlusManager.c, and SupplyDropPlusPlane.c to match the name of your mission**

- Inside of your init.c you need to find your MissionServer class.

**By default, it displayed as:** ```class CustomMission : MissionServer```

- Inside of your CustomMission class append the following:
```
	ref SupplyDropPlusManager airdrop;
	void CustomMission(){
		airdrop = new SupplyDropPlusManager();
	}

	override void OnUpdate(float timeslice){
		super.OnUpdate(timeslice);

		airdrop.onUpdate(timeslice);
	}
```

**Note: If you already have override void OnUpdate, and void CustomMission written you can add the following code in the following locations:**

- Above constructor:
```
ref SupplyDropPlusManager airdrop;
```

- Inside of constructor
```
airdrop = new SupplyDropPlusManager();
```

- Inside of override void OnUpdate()
```
airdrop.onUpdate();
```

