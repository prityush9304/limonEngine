//
// Created by engin on 26.05.2018.
//

#include <iostream>
#include "AddGuiTextOnTrigger.h"


TriggerRegister<AddGuiTextOnTrigger> AddGuiTextOnTrigger::reg("AddGuiTextOnTrigger");

std::vector<LimonAPI::ParameterRequest> AddGuiTextOnTrigger::getParameters() {
    std::vector<LimonAPI::ParameterRequest> parameters;
    LimonAPI::ParameterRequest pr;
    pr.valueType = LimonAPI::ParameterRequest::ValueTypes::STRING;
    pr.requestType = LimonAPI::ParameterRequest::RequestParameterTypes::FREE_TEXT;
    pr.description = "Name of GUI object";
    parameters.push_back(pr);
    LimonAPI::ParameterRequest pr2;
    pr2.valueType = LimonAPI::ParameterRequest::ValueTypes::STRING;
    pr2.requestType = LimonAPI::ParameterRequest::RequestParameterTypes::FREE_TEXT;
    pr2.description = "Text message to add as GUI element";
    parameters.push_back(pr2);

    return parameters;
}

bool AddGuiTextOnTrigger::run(std::vector<LimonAPI::ParameterRequest> parameters) {
    uint32_t guiID = limonAPI->addGuiText("Data/Fonts/Helvetica-Normal.ttf", 32, std::string(parameters[0].value.stringValue), std::string(parameters[1].value.stringValue),
            glm::vec3(0,255,255), glm::vec2(0.5f,0.3f), 0.0f);
    LimonAPI::ParameterRequest pr;
    pr.description = "Created GUI text id";
    pr.valueType = LimonAPI::ParameterRequest::ValueTypes::LONG;
    pr.requestType= LimonAPI::ParameterRequest::RequestParameterTypes::TRIGGER;
    pr.value.longValue = guiID;
    pr.isSet =true;
    this->result.push_back(pr);
    return true;
}

std::vector<LimonAPI::ParameterRequest> AddGuiTextOnTrigger::getResults() {
    std::vector<LimonAPI::ParameterRequest> temp = result;
    result.clear();
    return temp;//Not sure if clearing it was wrong
}

AddGuiTextOnTrigger::AddGuiTextOnTrigger(LimonAPI *limonAPI) : TriggerInterface(limonAPI) {}
