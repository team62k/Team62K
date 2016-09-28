//wallbot code Mk I
task autonomous(){
	startup();
	//insert autonomous code here
	AutonomousPlaceholderForTesting();
}

task usercontrol()
{
	startup();
	while(true){
		//insert remote control code here
		UserControlPlaceholderForTesting();
	}
}

void pre_auton(){
	
}

void startup(){
	
}
