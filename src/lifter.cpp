void lifter() {
	int presets[] = {4, 15, 25, 39}; // Preset angles of launcher.
		for (int b = 7; i <= 10; ++b) {
			if (rstick.GetRawButton(b) == true) {
				switch (b) {
					case 7:
						if (gyro.GetAngle > presets[0]) {
							do
							{
								lifterjag.Set(-1.0);
							} while (gyro.GetAngle != presets[0]);
						}

						else if (gyro.GetAngle == presets[0]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[0]) {
							do
							{
								lifterjag.Set(1.0);
							} while (gyro.GetAngle != presets[0]);
						}
					break;

					case 8:
						if (gyro.GetAngle > presets[1]) {
							do
							{
								lifterjag.Set(-1.0);
							} while (gyro.GetAngle != presets[1]);
						}

						else if (gyro.GetAngle == presets[1]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[1]) {
							do
							{
								lifterjag.Set(1.0);
							} while (gyro.GetAngle != presets[1]);
						}
					break;

					case 9:
						if (gyro.GetAngle > presets[2]) {
							do
							{
								lifterjag.Set(-1.0);
							} while (gyro.GetAngle != presets[2]);
						}

						else if (gyro.GetAngle == presets[2]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[2]) {
							do
							{
								lifterjag.Set(1.0);
							} while (gyro.GetAngle != presets[2]);
						}
					break;

					case 10:
						if (gyro.GetAngle > presets[3]) {
							do
							{
								lifterjag.Set(-1.0);
							} while (gyro.GetAngle != presets[3]);
						}

						else if (gyro.GetAngle == presets[3]) {
							// Do nothing, preset is already active.
						}

						else if (gyro.GetAngle < presets[3]) {
							do
							{
								lifterjag.Set(1.0);
							} while (gyro.GetAngle != presets[3]);
						}
					break;

				default: 
				break;
			}
		}

		else {
			// Do nothing; no buttons are pressed.
		}
	}
}