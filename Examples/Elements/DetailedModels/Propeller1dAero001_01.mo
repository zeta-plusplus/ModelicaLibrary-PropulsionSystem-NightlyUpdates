within PropulsionSystem.Examples.Elements.DetailedModels;

model Propeller1dAero001_01
  extends Modelica.Icons.Example;
  //-----
  package engineAir = Modelica.Media.Air.DryAirNasa;
  //-----
    inner EngineSimEnvironment environment annotation(
    Placement(visible = true, transformation(origin = {-90, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  inner Modelica.Fluid.System system annotation(
    Placement(visible = true, transformation(origin = {-70, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  PropulsionSystem.Elements.DetailedModels.Propeller1dAerodynamic propeller1dAerodynamic1(redeclare package Medium = engineAir) annotation(
    Placement(visible = true, transformation(origin = {-3.55271e-15, 20}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));
  Modelica.Fluid.Sources.Boundary_pT boundary(redeclare package Medium = engineAir,T = 288.15, nPorts = 1, p = 101.3 * 1000)  annotation(
    Placement(visible = true, transformation(origin = {-50, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const_flowAngle(k = 0)  annotation(
    Placement(visible = true, transformation(origin = {-50, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Constant const_bladeAngle(k = 85 * Modelica.Constants.pi / 180) annotation(
    Placement(visible = true, transformation(origin = {10, 70}, extent = {{-10, -10}, {10, 10}}, rotation = -90)));
  Modelica.Blocks.Sources.Ramp ramp_omega(duration = 10, height = 10 * 2 * Modelica.Constants.pi / 60, offset = 700 * 2 * Modelica.Constants.pi / 60, startTime = 10)  annotation(
    Placement(visible = true, transformation(origin = {90, 20}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Mechanics.Rotational.Sources.Speed speed1 annotation(
    Placement(visible = true, transformation(origin = {50, 20}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp_flowSpeed(duration = 10, height = 0, offset = 100, startTime = 10) annotation(
    Placement(visible = true, transformation(origin = {-50, -10}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(ramp_flowSpeed.y, propeller1dAerodynamic1.u_flowSpeed) annotation(
    Line(points = {{-38, -10}, {-30, -10}, {-30, 26}, {-22, 26}, {-22, 26}}, color = {0, 0, 127}));
  connect(const_bladeAngle.y, propeller1dAerodynamic1.u_bladeAngle) annotation(
    Line(points = {{10, 60}, {10, 42}}, color = {0, 0, 127}));
  connect(const_flowAngle.y, propeller1dAerodynamic1.u_flowAngle) annotation(
    Line(points = {{-39, 20}, {-34, 20}, {-34, 32}, {-22, 32}}, color = {0, 0, 127}));
  connect(propeller1dAerodynamic1.flange_2, speed1.flange) annotation(
    Line(points = {{20, 20}, {40, 20}}));
  connect(boundary.ports[1], propeller1dAerodynamic1.port_1) annotation(
    Line(points = {{-40, 50}, {-28, 50}, {-28, 36}, {-20, 36}}, color = {0, 127, 255}));
  connect(speed1.w_ref, ramp_omega.y) annotation(
    Line(points = {{62, 20}, {80, 20}, {80, 20}, {78, 20}}, color = {0, 0, 127}));
annotation(
    experiment(StartTime = 0, StopTime = 30, Tolerance = 1e-6, Interval = 0.01),
    __OpenModelica_simulationFlags(lv = "LOG_STATS", outputFormat = "mat", s = "dassl"));end Propeller1dAero001_01;