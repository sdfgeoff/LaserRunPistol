-- tup.creategitignore()

gen_stls = tup.foreach_rule('*.stl.FCStd', '^o^' .. python .. '$(TOP)/tools/export_freecad.py %f %o', '$(MODEL_FOLDER)/%B')
gen_step = tup.foreach_rule('*.step.FCStd', '^o^' .. python .. '$(TOP)/tools/export_freecad.py %f %o', '$(MODEL_FOLDER)/%B')

-- $(HIDE)$(PYTHON3) $(PROJECT_DIR)/tools/export_gcode.py $< $@
gen_gcode = tup.foreach_rule(gen_stls, 'python $(TOP)/tools/stl_to_gcode.py %f %o', '$(GCODE_FOLDER)/%B.gcode')
