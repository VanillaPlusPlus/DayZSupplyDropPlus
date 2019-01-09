//////////////////////////////////////////////
//Airdrop System 			   			 	//
//Author: GravityWolf 					 	//
//Github: github.com/gravitywolfnotamused	//
//////////////////////////////////////////////

typedef array<ref SupplyCratePlus> Supplies;

class SupplyCratePlus{
	private vector position;

	private Object package;
	private EntityAI packageAI;

	private bool m_HasGravity = false;
	private float currentLifeTime = 0;

	void SupplyCratePlus(vector position, ref array<string> pickedLoot){
		this.position = position;

		package = GetGame().CreateObject("SeaChest", position, false, true);
	 	package.SetDirection(package.GetDirection());
        package.SetPosition(Vector(package.GetPosition()[0],700,package.GetPosition()[2]));

		if(Class.CastTo(packageAI, package)){
			foreach(string s : pickedLoot){
				packageAI.GetInventory().CreateInInventory(s);
			}
		}
		Print("Carepackage created at: " + position.ToString());
	}

	void applyGravity(){
		m_HasGravity = true;
		dBodySetLinearFactor(package, "0 -2 0");
		dBodyDestroy( package );
		autoptr PhysicsGeomDef geoms[] = { PhysicsGeomDef("", dBodyGetGeom(package, "seachest"), "material/default", 0xffffffff )};
		dBodyCreateDynamicEx( package, dBodyGetCenterOfMass( package ), 500, geoms );
	}

	float getLifeTime(){
		return currentLifeTime;
	}
	void setCurrentLifetime(float Time){
		currentLifeTime += Time;
	}

	
	bool hasGravity()
	{
		return m_HasGravity;
	}

	vector getPosition(){
		return position;
	}
	void setPosition(vector position){
		this.position = position;
		package.SetPosition(position);
	}

	Object getObject(){
		return package;
	}
	
	float getEndY(){
		return GetGame().SurfaceY(position[0], position[2]);
	}

	vector getEndYVector(){
		vector endVec = this.position;
		endVec[1] = getEndY();
		return endVec;
	}
}