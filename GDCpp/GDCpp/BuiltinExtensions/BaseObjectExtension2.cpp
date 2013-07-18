#include "GDCpp/BuiltinExtensions/BaseObjectExtension.h"
#include "GDCore/Events/EventsCodeGenerator.h"
#include "GDCore/Events/EventsCodeGenerationContext.h"
#include "GDCore/Events/EventsCodeNameMangler.h"
#include "GDCore/Events/ExpressionsCodeGeneration.h"

void BaseObjectExtension::DeclareExtensionSecondPart()
{
    #if defined(GD_IDE_ONLY)
    AddAction("Create",
                   _("Create an object"),
                   _("Create an object at specified position"),
                   _("Create object _PARAM1_ at position _PARAM2_;_PARAM3_"),
                   _("Objects"),
                   "res/actions/create24.png",
                   "res/actions/create.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectListWithoutPicking", _("Object to create"))
        .AddParameter("expression", _("X position"))
        .AddParameter("expression", _("Y position"))
        .AddParameter("layer", _("Layer ( Base layer if empty )"), "", true).SetDefaultValue("\"\"")
        .codeExtraInformation.SetFunctionName("CreateObjectOnScene").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");

    AddAction("CreateByName",
                   _("Create an object from its name"),
                   _("Among the objects of the specified group, the action will create the object with the specified name."),
                   _("Among objects _PARAM1_, create object named _PARAM2_ at position _PARAM3_;_PARAM4_"),
                   _("Objects"),
                   "res/actions/create24.png",
                   "res/actions/create.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectListWithoutPicking", _("Groups containing objects which can be created by the action"))
        .AddParameter("string", _("Text representing the name of the object to create"))
        .AddParameter("expression", _("X position"))
        .AddParameter("expression", _("Y position"))
        .AddParameter("layer", _("Layer ( Base layer if empty )"), "", true).SetDefaultValue("\"\"")
        .codeExtraInformation.SetFunctionName("CreateObjectFromGroupOnScene").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");

    AddAction("AjoutObjConcern",
                   _("Consider objects"),
                   _("Pick all objects with this name."),
                   _("Consider all _PARAM1_ "),
                   _("Objects"),
                   "res/actions/add24.png",
                   "res/actions/add.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectList", _("Object"))
        .codeExtraInformation.SetFunctionName("PickAllObjects").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");

    AddAction("AjoutHasard",
                   _("Take a random object"),
                   _("Take only one object with this name among all"),
                   _("Take a random _PARAM1_ "),
                   _("Objects"),
                   "res/actions/ajouthasard24.png",
                   "res/actions/ajouthasard.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectList", _("Object"))
        .codeExtraInformation.SetFunctionName("PickRandomObject").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");

    AddAction("MoveObjects",
                   _("Make objects moving"),
                   _("Moves the objects according to the forces they have.Game Develop call this action at the end of the events by default."),
                   _("Make objects moving"),
                   _("Displacement"),
                   "res/actions/doMove24.png",
                   "res/actions/doMove.png")
        .AddCodeOnlyParameter("currentScene", "")
        .codeExtraInformation.SetFunctionName("MoveObjects").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");

    AddCondition("SeDirige",
                   _("An object is moving to another"),
                   _("Test if an object moves towards another.\nThe first object must move."),
                   _("_PARAM0_ is moving toward _PARAM1_"),
                   _("Displacement"),
                   "res/conditions/sedirige24.png",
                   "res/conditions/sedirige.png")
        .AddParameter("objectList", _("Object"))
        .AddParameter("objectList", _("Object 2"))
        .AddParameter("expression", _("Angle of tolerance"))
        .AddCodeOnlyParameter("conditionInverted", "")
        .codeExtraInformation.SetFunctionName("MovesToward").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");



    AddCondition("Distance",
                   _("Distance between two objects"),
                   _("Test the distance between two objects."),
                   _("The distance between _PARAM0_ and _PARAM1_ is below _PARAM2_ pixels"),
                   _("Position"),
                   "res/conditions/distance24.png",
                   "res/conditions/distance.png")
        .AddParameter("objectList", _("Object"))
        .AddParameter("objectList", _("Object 2"))
        .AddParameter("expression", _("Distance"))
        .AddCodeOnlyParameter("conditionInverted", "")
        .codeExtraInformation.SetFunctionName("DistanceBetweenObjects").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");



    AddCondition("AjoutObjConcern",
                   _("Consider objects"),
                   _("Pick all objects with this name."),
                   _("Consider all _PARAM1_ "),
                   _("Objects"),
                   "res/conditions/add24.png",
                   "res/conditions/add.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectList", _("Object"))
        .codeExtraInformation.SetFunctionName("PickAllObjects").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");



    AddCondition("AjoutHasard",
                   _("Take a random object"),
                   _("Take only one object with this name among all"),
                   _("Take a random _PARAM1_ "),
                   _("Objects"),
                   "res/conditions/ajouthasard24.png",
                   "res/conditions/ajouthasard.png")
        .AddCodeOnlyParameter("currentScene", "")
        .AddParameter("objectList", _("Object"))
        .codeExtraInformation.SetFunctionName("PickRandomObject").SetIncludeFile("GDCpp/BuiltinExtensions/RuntimeSceneTools.h");



    AddCondition("NbObjet",
                   _("Number of objects"),
                   _("Test the number of concerned objects."),
                   _("The number of _PARAM0_ is _PARAM1__PARAM2_"),
                   _("Objects"),
                   "res/conditions/nbObjet24.png",
                   "res/conditions/nbObjet.png")
        .AddParameter("objectList", _("Object"))
        .AddParameter("relationalOperator", _("Sign of the test"))
        .AddParameter("expression", _("Value to test"))
        .codeExtraInformation.SetFunctionName("PickedObjectsCount").SetManipulatedType("number").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");

    AddCondition("CollisionNP", //"CollisionNP" cames from an old condition to test collision between two sprites non precisely.
                   _("Collision"),
                   _("Test the collision between two objects using their collision mask.\nNote that some objects may not have a collision mask.\nSome others, like Sprite, provide also more precise collision conditions."),
                   _("_PARAM0_ is in collision with _PARAM1_ ( Collision masks )"),
                   _("Collision"),
                   "res/conditions/collision24.png",
                   "res/conditions/collision.png")
        .AddParameter("objectList", _("Object"))
        .AddParameter("objectList", _("Object"))
        .AddCodeOnlyParameter("conditionInverted", "")
        .codeExtraInformation.SetFunctionName("HitBoxesCollision").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");

    AddCondition("EstTourne",
                      _("An object is turned toward another"),
                      _("Test if an object is turned toward another"),
                      _("_PARAM0_ is rotated towards _PARAM1_"),
                      _("Angle"),
                      "res/conditions/estTourne24.png",
                      "res/conditions/estTourne.png")
        .AddParameter("objectList", _("Name of the object"), "", false)
        .AddParameter("objectList", _("Name of the second object"))
        .AddParameter("expression", _("Angle of tolerance, in degrees (0: minimum tolerance)"), "",false)
        .AddCodeOnlyParameter("conditionInverted", "")
        .codeExtraInformation.SetFunctionName("ObjectsTurnedToward").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");


    AddExpression("Count", _("Number of objects"), _("Count the number of specified objects currently concerned"), _("Objects"), "res/conditions/nbObjet.png")
        .AddParameter("objectList", _("Object"))
        .codeExtraInformation.SetFunctionName("PickedObjectsCount").SetIncludeFile("GDCpp/BuiltinExtensions/ObjectTools.h");

    #endif
}

