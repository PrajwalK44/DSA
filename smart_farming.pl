% Facts about soil quality
soil_quality(soil_type(clay), good).
soil_quality(soil_type(sand), moderate).
soil_quality(soil_type(loam), excellent).

% Facts about weather conditions
weather_condition(sunny).
weather_condition(rainy).
weather_condition(windy).

% Facts about crops
crop_type(corn).
crop_type(wheat).

% Facts about irrigation requirements
irrigation_needs(corn, high).
irrigation_needs(wheat, medium).

% Facts about pests
pest_presence(corn, yes).
pest_presence(wheat, no).

% Facts about fertilizers
fertilizer_need(corn, high).
fertilizer_need(wheat, low).












% Rule for deciding if irrigation is needed
needs_irrigation(Crop) :-
    crop_type(Crop),
    irrigation_needs(Crop, high),
    weather_condition(sunny).

needs_irrigation(Crop) :-
    crop_type(Crop),
    irrigation_needs(Crop, medium),
    weather_condition(rainy).

% Rule for deciding fertilizer application
needs_fertilizer(Crop) :-
    crop_type(Crop),
    fertilizer_need(Crop, high).

% Rule for pest control
needs_pest_control(Crop) :-
    crop_type(Crop),
    pest_presence(Crop, yes).
    
% Rule for optimal planting advice based on soil
optimal_soil_for_crop(Crop, SoilType) :-
    crop_type(Crop),
    soil_quality(soil_type(SoilType), excellent).
