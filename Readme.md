# About

The sport of Obstacle Racing sometimes it include a shooting component done with laser pistols. 
For competetions, these are often UIPM approved ones, often provided by the event organizers. But
what if you want one at home to practice with? You're looking at thousands of dollars! Ouch! I was surprised to
find that no-one has built a 3D printable practice laser gun yet!

So this project aims to build a laser gun that is:
 1. (mostly) compliant with UIPM's ruleset (though it probably can't be approved, being an open source project)
 2. Easily constructable by your friendly neighborhood 3d-printing-nerd/maker.
 3. Usable with gun-training-laser-simulator-phone apps (eg laserhit, shootermakeready)


# Requirements


## UIPM Regulations:

This laser pistol is based on the UIPM's 2025 rule guide. You can find
this here: https://www.uipmworld.org/uipm-rules-and-regulations

### 5.8 THE LASER PISTOL

1. Only single shot pistol is allowed without any form of magazine or clip. The shot must be activated
by a mechanical trigger (trigger lever movement). Electronical triggers are forbidden but sensors and
actuators for activating the emitting of the Laser signal can be used within the pistol.

2. The single shot laser pistol must be loaded by a loading lever, which needs to be operated by the
non-shooting hand. The loading lever must serve the purpose of loading each (laser) shot. The
loading lever must be opened mechanically by hand, and with a movement from 0° to a minimum
of 35° before the next shot will be enabled.

3. The overall size of the complete pistol is limited to dimensions which permit it to be enclosed
completely in a rectangular box with inside dimensions of 420mm x 200mm x 50mm. A
manufacturing tolerance of + 1.0 mm in the dimensions of the box is permitted. The minimum
overall size is 20% of the above dimensions (336mm x 160mm x 40mm) with the same tolerance. In
each axes the size of the pistol must be greater than or equal to the Minimum-Dimension.

4. Only open sights are allowed. Optical mirror, telescope, laser-beam, electronic sights, active lights,
activated material (other than by ambient light) or electronically projected dot sights are prohibited.
Any aiming device programmed to activate the firing mechanism or to give an indication to this is
prohibited. No protective covering is permitted on front or rear sights. There should be possibility of
vertical and horizontal aiming correction.

5. No part of the grip or accessories may encircle the hand. The heel rest must extend at an angle not
less than 90º to the grip. Any upward curvature of the heel and/or thumb rests and/or downward
curvature of the side opposite the thumb is prohibited (see figure 2). The thumb support must allow
the free upward vertical movement of the thumb. However, curved surfaces on the grips or frame,
including the heel and/or thumb rest (see figures 3 and 4) in the longitudinal direction of the pistol
are permitted.

6. Only one (1) laser cartridge/module per pistol is allowed.

7. The laser cartridge must carry the UIPM laser signal of 15.6 ms laser signal duration, red colour
(635-650 nm), ± 10 nm. The laser power must be in the range of 2.5 mw–3.4 mw. The technical
specifications concerning the UIPM laser signal (shot signal) are given in details in the UIPM
document “Technical Specifications Laser Shooting” and in the current UIPM Homologation
documents.

8. The following items can be tested at competitions by the Equipment Control Officers:

    1. weight and overall size of pistol;
    2. whether the used laser modules comply with the specified max./min. laser power;
    3. wavelength of the Laser: 635 to 650nm ± 10 nm;
    4. the parameters of the embedded and approved UIPM laser signal, (also called “short laser signal”);
    5. beam diameter: max. 6mm at 10 m distance;
    6. the time the laser beam is released from the pistol, after pushing the trigger, must be between 6ms and 10ms;
    7. wire and radio free;
    8. after approval for the competition the change of any setting for that competition period is blocked.
    
9. Laser security: The used laser modules must comply with laser class 1 (EN 60825-1:2014/IEC
60825-1:2014, and all updates) in view of the UIPM laser signal 15.6. The providers are responsible to
provide a certificate for each type of the laser modules they have embedded in their pistols and
cartridges intended for the use in Modern Pentathlon.


## Geoff's Requirements

1. Constructed out of the following materials:
    1. 3D printing - on a normal printer with print volume of ~250mm cube
    2. ESP32 or other low cost microcontroller (I like the ESP32)
    3. 18650 battery for power
    4. Commonly available laser module (12mm diameter seems pretty common)
    5. Commonly available switches (KW-12 microswitch, SS-12F15G4 toggle switch)
    6. Commonly available LED's (5mm round)
    7. Use finite number of bolt sizes:
        - M3x10
        - M3x20
        - M2x10
    8. Additional/adjustable weights may be allowed if they are available at hardware stored (eg M8 rod)

2. Modular design allowing redesign/reintegration without requiring reprinting the entire pistol.
The following modules are proposed:
    - Frame (holding electronics, laser and battery)
    - Handgrip and wrist-plate
    - Trigger Mechanism
    - Loading Mechanism
    - Front and Rear Sights

3. Functions with commonly available laser-dry-fire phone apps such as laserhit, shootermakeready.

4. Software and CAD files open source, cloneable, editable using common/free software

5. "Normal" target pistol properties such as:
    1. Adjustable dual stage trigger (that doesn't require reprinting)
    2. Adjustable sights 

## Requirement Conflicts

1. *Laser Pulse Duration*. UIPM mandates a 15.6ms laser pulse. This is 1/60th of a second. Most phone apps use the cellphone
camera and so need pulse a duration of at least 1/30th of a second to be picked up reliably. As this is a simulator and not
likely to be used in actual contests, the pulse duration shall default to 1/30th of a second.
