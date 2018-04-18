#pragma config(Motor,  port1,           RightRear,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           RightTower,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LeftTower,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           Wrist,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ExtArm,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           LeftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          LeftRear,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Claw:    + Closes
// Wrist:   + Up
// Ext Arm: + Extends
// Tower:   + Up
task main()
{
	while (true) {
		// Left:  V:Ch3 H:Ch4
		// Right: V:Ch2 H:Ch1
		int arcade_fwrd = vexRT[Ch2];
		int arcade_turn = vexRT[Ch1];
		int crab_side = vexRT[Ch4];
		int crab_fwrd = vexRT[Ch3];

		motor[RightFront] = 1.0 * (arcade_fwrd + crab_fwrd - arcade_turn - crab_side);
		motor[RightRear]  = 1.0 * (arcade_fwrd + crab_fwrd - arcade_turn + crab_side);
		motor[LeftFront]  = 1.0 * (arcade_fwrd + crab_fwrd + arcade_turn + crab_side);
		motor[LeftRear]   = 1.0 * (arcade_fwrd + crab_fwrd + arcade_turn - crab_side);

		// Btn 5 U & D: Tower
		int tower = 50 * (vexRT[Btn5U] - vexRT[Btn5D]);
	  motor[RightTower] = tower;
	  motor[LeftTower]  = tower;

	  // Btn 7 U & D: Extend arm
	  motor[ExtArm] = 127 * (vexRT[Btn7U] - vexRT[Btn7D]);

	  // Claw & Wrist: 8 L & R, U & D
	  motor[Claw]  = 50 * (vexRT[Btn8R] - vexRT[Btn8L]);
	  motor[Wrist] = 50 * (vexRT[Btn8U] - vexRT[Btn8D]);
  }
}
