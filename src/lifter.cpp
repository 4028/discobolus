void lifter() {
	int presets[] = {4, 15, 25, 39}; // Preset angles of launcher.
		for (int b = 7; i <= 10; ++b) { // For loop iterates through all of the buttons.
			if (rstick.GetRawButton(b) == true) { // Checks iterated value, if none are pressed switch statement is not executed.
				switch (b) {
					case 7: // If b == button 7, do the following:
						if (gyro.GetAngle > presets[0]) {
							do
							{
								lifterjag.Set(-1.0); // Gyro angle is greater than preset angle, lower until they are equal.
							} while (gyro.GetAngle != presets[0]);
						}

						else if (gyro.GetAngle == presets[0]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[0]) {
							do
							{
								lifterjag.Set(1.0); // Gyro's angle is less than preset angle, raise until they are equal.
							} while (gyro.GetAngle != presets[0]);
						}
					break;

					case 8:// If b == button 8, do the following:
						if (gyro.GetAngle > presets[1]) {
							do
							{
								lifterjag.Set(-1.0); // Gyro angle is greater than preset angle, lower until they are equal.
							} while (gyro.GetAngle != presets[1]);
						}

						else if (gyro.GetAngle == presets[1]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[1]) {
							do
							{
								lifterjag.Set(1.0); // Gyro's angle is less than preset angle, raise until they are equal.
							} while (gyro.GetAngle != presets[1]);
						}
					break;

					case 9:// If b == button 9, do the following:
						if (gyro.GetAngle > presets[2]) {
							do
							{
								lifterjag.Set(-1.0); // Gyro angle is greater than preset angle, lower until they are equal.
							} while (gyro.GetAngle != presets[2]);
						}

						else if (gyro.GetAngle == presets[2]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[2]) {
							do
							{
								lifterjag.Set(1.0); // Gyro's angle is less than preset angle, raise until they are equal.
							} while (gyro.GetAngle != presets[2]);
						}
					break;

					case 10:// If b == button 10, do the following:
						if (gyro.GetAngle > presets[3]) {
							do
							{
								lifterjag.Set(-1.0); // Gyro angle is greater than preset angle, lower until they are equal.
							} while (gyro.GetAngle != presets[3]);
						}

						else if (gyro.GetAngle == presets[3]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[3]) {
							do
							{
								lifterjag.Set(1.0); // Gyro's angle is less than preset angle, raise until they are equal.
							} while (gyro.GetAngle != presets[3]);
						}
					break;
			}
		}

		else {
			// Do nothing; no buttons are pressed.
		}
	}
}