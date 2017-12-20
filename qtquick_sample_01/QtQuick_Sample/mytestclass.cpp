#include <QThread>
#include <QSettings>
#include "mytestclass.h"

MyTestClass::MyTestClass(QObject *parent) : QObject(parent)
  , m_AppModel_NameMap()
{
    static_cast<void>(QObject::connect(this, SIGNAL(signalForLoadConfigFile()), this, SLOT(loadConfigFile()), Qt::AutoConnection));

    init_AppModelNameMap();

    QMetaEnum my_enum = QMetaEnum::fromType<Test_Enum>();

    for (int loop=0; loop<my_enum.keyCount(); ++loop)
    {
        qDebug("%s=%d", my_enum.key(loop), my_enum.value(loop));
    }
}

void MyTestClass::loadConfigFileInterfaceForQML()
{
    qDebug("Called loadConfigFileInterfaceForQML ~~");
    emit signalForLoadConfigFile();
}

typedef union{
    quint32 function_status;
    struct{
        quint32 MechanicalSpeed:1;
        quint32 GPSLocation:1;
        quint32 CompassHeading:1;
        quint32 DayNightMode:1;
        quint32 ParkingBrake:1;
        quint32 CurrentGear:1;
        quint32 DriveLevel:1;
        quint32 RPM:1;
        quint32 Odometer:1;
        quint32 Fuel:1;
        quint32 :1;
        quint32 EnvironmentalPressure:1;
        quint32 HVAC:1;
        quint32 :1;
        quint32 PassengerPresence:1;
        quint32 DoorTrunkHoodStatus:1;
        quint32 Headlights:1;
        quint32 TirePressure:1;
        quint32 Accelerometer:1;
        quint32 Gyroscope:1;
        quint32 GPSSatelliteStatus:1;
        quint32 :11;
    }bf;
}FuncsConf_st;

static const char *APP_MODEL_CONFIG_FILENAME = "../app_model.conf";

enum App_Model_Conf{
    MAINSCREENPIXELS            ,
    FPS                         ,
    HORIZONTALMARGIN_7INCH      ,
    HORIZONTALMARGIN_8INCH      ,
    HORIZONTALMARGIN_9INCH      ,
    HORIZONTALMARGIN_9INCH_1    ,
    HORIZONTALMARGIN_10INCH     ,
    VERTICALMARGIN_7INCH        ,
    VERTICALMARGIN_8INCH        ,
    VERTICALMARGIN_9INCH        ,
    VERTICALMARGIN_9INCH_1      ,
    VERTICALMARGIN_10INCH       ,
    DPI_7INCH                   ,
    DPI_8INCH                   ,
    DPI_9INCH                   ,
    DPI_9INCH_1                 ,
    DPI_10INCH                  ,
    VIEWINGDISTANCE_7INCH       ,
    VIEWINGDISTANCE_8INCH       ,
    VIEWINGDISTANCE_9INCH       ,
    VIEWINGDISTANCE_9INCH_1     ,
    VIEWINGDISTANCE_10INCH      ,
    PAR_7INCH                   ,
    PAR_8INCH                   ,
    PAR_9INCH                   ,
    PAR_9INCH_1                 ,
    PAR_10INCH                  ,
    TPSUPPORT                   ,
    TPKIND                      ,
    KNOB                        ,
    ROTATE                      ,
    BTPAIRINGKIND               ,
    NAVISTATUSFREQ              ,
    ARROWNAVI                   ,
    ARROWNAVIVERTICALPIXEL      ,
    ARROWNAVIHORIZONTALPIXEL    ,
    ARROWNAVICOLORDEPTH         ,
    CARGPSCORRECT               ,
};

void MyTestClass::init_AppModelNameMap(void)
{
    static_cast<void>(m_AppModel_NameMap.insert( MAINSCREENPIXELS               ,   "MainScreenPixels"          ));
    static_cast<void>(m_AppModel_NameMap.insert( FPS                            ,   "FPS"                       ));
    static_cast<void>(m_AppModel_NameMap.insert( HORIZONTALMARGIN_7INCH         ,   "HorizontalMargin_7inch"    ));
    static_cast<void>(m_AppModel_NameMap.insert( HORIZONTALMARGIN_8INCH         ,   "HorizontalMargin_8inch"    ));
    static_cast<void>(m_AppModel_NameMap.insert( HORIZONTALMARGIN_9INCH         ,   "HorizontalMargin_9inch"    ));
    static_cast<void>(m_AppModel_NameMap.insert( HORIZONTALMARGIN_9INCH_1       ,   "HorizontalMargin_9inch_1"  ));
    static_cast<void>(m_AppModel_NameMap.insert( HORIZONTALMARGIN_10INCH        ,   "HorizontalMargin_10inch"   ));
    static_cast<void>(m_AppModel_NameMap.insert( VERTICALMARGIN_7INCH           ,   "VerticalMargin_7inch"      ));
    static_cast<void>(m_AppModel_NameMap.insert( VERTICALMARGIN_8INCH           ,   "VerticalMargin_8inch"      ));
    static_cast<void>(m_AppModel_NameMap.insert( VERTICALMARGIN_9INCH           ,   "VerticalMargin_9inch"      ));
    static_cast<void>(m_AppModel_NameMap.insert( VERTICALMARGIN_9INCH_1         ,   "VerticalMargin_9inch_1"    ));
    static_cast<void>(m_AppModel_NameMap.insert( VERTICALMARGIN_10INCH          ,   "VerticalMargin_10inch"     ));
    static_cast<void>(m_AppModel_NameMap.insert( DPI_7INCH                      ,   "DPI_7inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( DPI_8INCH                      ,   "DPI_8inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( DPI_9INCH                      ,   "DPI_9inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( DPI_9INCH_1                    ,   "DPI_9inch_1"               ));
    static_cast<void>(m_AppModel_NameMap.insert( DPI_10INCH                     ,   "DPI_10inch"                ));
    static_cast<void>(m_AppModel_NameMap.insert( VIEWINGDISTANCE_7INCH          ,   "ViewingDistance_7inch"     ));
    static_cast<void>(m_AppModel_NameMap.insert( VIEWINGDISTANCE_8INCH          ,   "ViewingDistance_8inch"     ));
    static_cast<void>(m_AppModel_NameMap.insert( VIEWINGDISTANCE_9INCH          ,   "ViewingDistance_9inch"     ));
    static_cast<void>(m_AppModel_NameMap.insert( VIEWINGDISTANCE_9INCH_1        ,   "ViewingDistance_9inch_1"   ));
    static_cast<void>(m_AppModel_NameMap.insert( VIEWINGDISTANCE_10INCH         ,   "ViewingDistance_10inch"    ));
    static_cast<void>(m_AppModel_NameMap.insert( PAR_7INCH                      ,   "PAR_7inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( PAR_8INCH                      ,   "PAR_8inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( PAR_9INCH                      ,   "PAR_9inch"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( PAR_9INCH_1                    ,   "PAR_9inch_1"               ));
    static_cast<void>(m_AppModel_NameMap.insert( PAR_10INCH                     ,   "PAR_10inch"                ));
    static_cast<void>(m_AppModel_NameMap.insert( TPSUPPORT                      ,   "TPSupport"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( TPKIND                         ,   "TPKind"                    ));
    static_cast<void>(m_AppModel_NameMap.insert( KNOB                           ,   "Knob"                      ));
    static_cast<void>(m_AppModel_NameMap.insert( ROTATE                         ,   "Rotate"                    ));
    static_cast<void>(m_AppModel_NameMap.insert( BTPAIRINGKIND                  ,   "BTPairingKind"             ));
    static_cast<void>(m_AppModel_NameMap.insert( NAVISTATUSFREQ                 ,   "NaviStatusFreq"            ));
    static_cast<void>(m_AppModel_NameMap.insert( ARROWNAVI                      ,   "ArrowNavi"                 ));
    static_cast<void>(m_AppModel_NameMap.insert( ARROWNAVIVERTICALPIXEL         ,   "ArrowNaviVerticalPixel"    ));
    static_cast<void>(m_AppModel_NameMap.insert( ARROWNAVIHORIZONTALPIXEL       ,   "ArrowNaviHorizontalPixel"  ));
    static_cast<void>(m_AppModel_NameMap.insert( ARROWNAVICOLORDEPTH            ,   "ArrowNaviColorDepth"       ));
    static_cast<void>(m_AppModel_NameMap.insert( CARGPSCORRECT                  ,   "CarGPSCorrect"             ));
}

#define SESSIONINFO_DEFAULT_GPSSATELLITESTATUS                  (1U)
#define SESSIONINFO_DEFAULT_GYROSCOPE                           (1U)
#define SESSIONINFO_DEFAULT_ACCELEROMETER                       (1U)
#define SESSIONINFO_DEFAULT_TIREPRESSURE                        (0U)
#define SESSIONINFO_DEFAULT_HEADLIGHTS                          (0U)
#define SESSIONINFO_DEFAULT_DOORTRUNKHOODSTATUS                 (0U)
#define SESSIONINFO_DEFAULT_PASSENGERPRESENCE                   (0U)
#define SESSIONINFO_DEFAULT_HVAC                                (0U)
#define SESSIONINFO_DEFAULT_ENVIRONMENTALPRESSURE               (0U)
#define SESSIONINFO_DEFAULT_FUEL                                (0U)
#define SESSIONINFO_DEFAULT_ODOMETER                            (0U)
#define SESSIONINFO_DEFAULT_RPM                                 (0U)
#define SESSIONINFO_DEFAULT_DRIVELEVEL                          (1U)
#define SESSIONINFO_DEFAULT_CURRENTGEAR                         (0U)
#define SESSIONINFO_DEFAULT_PARKINGBRAKE                        (1U)
#define SESSIONINFO_DEFAULT_DAYNIGHTMODE                        (1U)
#define SESSIONINFO_DEFAULT_COMPASSHEADING                      (1U)
#define SESSIONINFO_DEFAULT_GPSLOCATION                         (1U)
#define SESSIONINFO_DEFAULT_MECHANICALSPEED                     (1U)


void MyTestClass::loadConfigFile(void)
{
    QByteArray temparray;
    QByteArray finalarray;
    temparray[0] = 0x0A;
    temparray[1] = 0x0B;
    temparray[2] = 0x0C;
    temparray[3] = 0x0D;
    temparray[4] = 0x0E;
    temparray[5] = 0x0F;

    QVariant temp_Var(temparray);
    QString temp_str = temp_Var.toString();
    finalarray = temp_str.toLatin1();
    qDebug("temp_Var=%s", temp_str.toLatin1().constData());

    qDebug("Called loadConfigFile ~~");
    qDebug("App Thread ID:0x%08X", QThread::currentThreadId());

    QPixmap tempPixmap("D:/Sample_bitmap_01.bmp");

    qDebug() << tempPixmap.isNull();

    QSettings generalSettings(QString(APP_MODEL_CONFIG_FILENAME), QSettings::IniFormat);
    bool convert_Result;
    const char * configItemName;

    FuncsConf_st other_funcs;
    other_funcs.function_status = 0;

    configItemName = "GPSSatelliteStatus";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.GPSSatelliteStatus = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.GPSSatelliteStatus = SESSIONINFO_DEFAULT_GPSSATELLITESTATUS;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.GPSSatelliteStatus = SESSIONINFO_DEFAULT_GPSSATELLITESTATUS;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Gyroscope";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.Gyroscope = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.Gyroscope = SESSIONINFO_DEFAULT_GYROSCOPE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.Gyroscope = SESSIONINFO_DEFAULT_GYROSCOPE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Accelerometer";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.Accelerometer = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.Accelerometer = SESSIONINFO_DEFAULT_ACCELEROMETER;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.Accelerometer = SESSIONINFO_DEFAULT_ACCELEROMETER;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "TirePressure";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.TirePressure = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.TirePressure = SESSIONINFO_DEFAULT_TIREPRESSURE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.TirePressure = SESSIONINFO_DEFAULT_TIREPRESSURE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Headlights";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.Headlights = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.Headlights = SESSIONINFO_DEFAULT_HEADLIGHTS;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.Headlights = SESSIONINFO_DEFAULT_HEADLIGHTS;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "DoorTrunkHoodStatus";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.DoorTrunkHoodStatus = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.DoorTrunkHoodStatus = SESSIONINFO_DEFAULT_DOORTRUNKHOODSTATUS;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.DoorTrunkHoodStatus = SESSIONINFO_DEFAULT_DOORTRUNKHOODSTATUS;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "PassengerPresence";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.PassengerPresence = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.PassengerPresence = SESSIONINFO_DEFAULT_PASSENGERPRESENCE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{        
        other_funcs.bf.PassengerPresence = SESSIONINFO_DEFAULT_PASSENGERPRESENCE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "HVAC";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.HVAC = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.HVAC = SESSIONINFO_DEFAULT_HVAC;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.HVAC = SESSIONINFO_DEFAULT_HVAC;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "EnvironmentalPressure";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.EnvironmentalPressure = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.EnvironmentalPressure = SESSIONINFO_DEFAULT_ENVIRONMENTALPRESSURE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.EnvironmentalPressure = SESSIONINFO_DEFAULT_ENVIRONMENTALPRESSURE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Fuel";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.Fuel = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.Fuel = SESSIONINFO_DEFAULT_FUEL;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.Fuel = SESSIONINFO_DEFAULT_FUEL;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Odometer";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.Odometer = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.Odometer = SESSIONINFO_DEFAULT_ODOMETER;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.Odometer = SESSIONINFO_DEFAULT_ODOMETER;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "RPM";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.RPM = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.RPM = SESSIONINFO_DEFAULT_RPM;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.RPM = SESSIONINFO_DEFAULT_RPM;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "DriveLevel";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.DriveLevel = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.DriveLevel = SESSIONINFO_DEFAULT_DRIVELEVEL;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.DriveLevel = SESSIONINFO_DEFAULT_DRIVELEVEL;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "CurrentGear";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.CurrentGear = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.CurrentGear = SESSIONINFO_DEFAULT_CURRENTGEAR;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.CurrentGear = SESSIONINFO_DEFAULT_CURRENTGEAR;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "ParkingBrake";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.ParkingBrake = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.ParkingBrake = SESSIONINFO_DEFAULT_PARKINGBRAKE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.ParkingBrake = SESSIONINFO_DEFAULT_PARKINGBRAKE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "DayNightMode";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.DayNightMode = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.DayNightMode = SESSIONINFO_DEFAULT_DAYNIGHTMODE;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.DayNightMode = SESSIONINFO_DEFAULT_DAYNIGHTMODE;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "CompassHeading";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.CompassHeading = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.CompassHeading = SESSIONINFO_DEFAULT_COMPASSHEADING;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.CompassHeading = SESSIONINFO_DEFAULT_COMPASSHEADING;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "GPSLocation";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.GPSLocation = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.GPSLocation = SESSIONINFO_DEFAULT_GPSLOCATION;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.GPSLocation = SESSIONINFO_DEFAULT_GPSLOCATION;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "MechanicalSpeed";
    if (true == generalSettings.contains(configItemName)){
        quint32 value_config = generalSettings.value(configItemName).toUInt();
        if ((0 == value_config) || (1 == value_config)){
            other_funcs.bf.MechanicalSpeed = static_cast<quint8>(value_config);
        }
        else{
            other_funcs.bf.MechanicalSpeed = SESSIONINFO_DEFAULT_MECHANICALSPEED;
        }
        qDebug("[AppManager] ReadConf : %s=%d", configItemName, value_config);
    }
    else{
        other_funcs.bf.MechanicalSpeed = SESSIONINFO_DEFAULT_MECHANICALSPEED;
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    qDebug("function_status is 0x%08X", other_funcs.function_status);

    configItemName = "ArrowNavi";
    if (true == generalSettings.contains(configItemName)){
        bool bool_ArrowNavi = generalSettings.value(configItemName).toBool();
        qDebug("ArrowNavi=%s", true==bool_ArrowNavi?"true":"false");
    }
    else{
        qDebug("Not Found ArrowNavi");
    }

    configItemName = "Make";
    if (true == generalSettings.contains(configItemName)){
        if (true == generalSettings.value(configItemName).isNull()){
            qDebug("Make is NULL!");
        }
        class_string = generalSettings.value(configItemName).toString();
        class_bytearray = generalSettings.value(configItemName).toByteArray();
        if (class_bytearray.size() == 0){
            qDebug("Make size is 0");
        }
        class_variant = generalSettings.value(configItemName);
        qDebug("[AppManager] ReadConf : %s=%s(size:%d)", configItemName, class_string.toLatin1().constData(), class_string.toLatin1().length());
    }
    else{
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    configItemName = "Test";
    if (true == generalSettings.contains(configItemName)){
        class_string = generalSettings.value(configItemName).toString();
        class_bytearray = generalSettings.value(configItemName).toByteArray();
        class_variant = generalSettings.value(configItemName);
        qDebug("[AppManager] ReadConf : %s=%s(size:%d)", configItemName, class_bytearray.constData(), class_bytearray.length());
    }
    else{
        qDebug("[AppManager] ReadConf : %s(not found item)", configItemName);
    }

    //generalSettings.setValue("mytest", "ALPINE ELECTRONICS,INC.");

    configItemName = "FPS";
    //if (true == generalSettings.contains("FPS")){
    if (true == generalSettings.contains(configItemName)){
        QString string_FPS = generalSettings.value(configItemName).toString();
        uint value_FPS = string_FPS.toUInt(&convert_Result, 16);
        qDebug("FPS=0x%02X", value_FPS);
    }
    else{
        qDebug("Not Found FPS");
    }

    configItemName = "ArrowNavi";
    if (true == generalSettings.contains(configItemName)){
        bool bool_ArrowNavi = generalSettings.value(configItemName).toBool();
        qDebug("ArrowNavi=%s", true==bool_ArrowNavi?"true":"false");
    }
    else{
        qDebug("Not Found ArrowNavi");
    }

    configItemName = "BTPairingKind";
    if (true == generalSettings.contains(configItemName)){
        QString string_BTPairingKind = generalSettings.value(configItemName).toString();
        uint value_BTPairingKind = string_BTPairingKind.toUInt(&convert_Result, 16);
        qDebug("BTPairingKind=0x%08X", value_BTPairingKind);
    }
    else{
        qDebug("Not Found BTPairingKind");
    }

    configItemName = "NaviStatusFreq";
    if (true == generalSettings.contains(configItemName)){
        QString string_NaviStatusFreq = generalSettings.value(configItemName).toString();
        uint value_NaviStatusFreq = string_NaviStatusFreq.toUInt(&convert_Result, 16);
        qDebug("NaviStatusFreq=0x%04X", value_NaviStatusFreq);
    }
    else{
        qDebug("Not Found NaviStatusFreq");
    }

    configItemName = "PAR_7inch";
    if (true == generalSettings.contains(configItemName)){
        double value_PAR_7inch = generalSettings.value(configItemName).toDouble();
        //uint value_NaviStatusFreq = string_NaviStatusFreq.toUInt(&convert_Result, 16);
        qDebug("PAR_7inch=%f", value_PAR_7inch);
    }
    else{
        qDebug("Not Found PAR_7inch");
    }

//    if (true == generalSettings.contains("todaysay")){
//        QString todaySayStr = generalSettings.value("todaysay").toByteArray();
//        todaysayTextEdit->setPlainText(todaySayStr);
//    }

//    if (true == generalSettings.contains("autostart")){
//        bool autoStart = generalSettings.value("autostart").toBool();
//        if (true == autoStart){
//            startTimecheckBox->setCheckState(Qt::Checked);
//        }
//        else{
//            startTimecheckBox->setCheckState(Qt::Unchecked);
//        }
//    }

//    if (true == generalSettings.contains("starttime")){
//        QTime startTime = generalSettings.value("starttime").toTime();
//        starttimeEdit->setTime(startTime);
//    }

//    if (true == generalSettings.contains("endtime")){
//        QTime endTime = generalSettings.value("endtime").toTime();
//        endtimeEdit->setTime(endTime);
//    }

//    if (true == generalSettings.contains("autoshutdown")){
//        bool autoShutdown = generalSettings.value("autoshutdown").toBool();
//        if (true == autoShutdown){
//            shutdowncheckBox->setCheckState(Qt::Checked);
//        }
//        else{
//            shutdowncheckBox->setCheckState(Qt::Unchecked);
//        }
//    }

//    if (true == generalSettings.contains("resendtimer")){
//        int resendTimer = generalSettings.value("resendtimer").toInt();
//        ResendTimespinBox->setValue(resendTimer);
    //    }

    req_ReGenerateVehicleID();
}

void MyTestClass::threadStarted(void)
{
    qDebug("MyTestClass::threadStarted() Called");
    qDebug("App Thread ID:0x%08X", QThread::currentThreadId());
    qDebug("App Thread Name:%s", QThread::currentThread()->objectName().toLatin1().constData());
}

void MyTestClass::req_ReGenerateVehicleID(void)
{
    qDebug("[AppManager] req_ReGenerateVehicleID()");

    QFile fRandom("/dev/urandom");

    //if (fRandom.open(QIODevice::ReadOnly | QIODevice::Text)) {
    if (fRandom.open(QIODevice::ReadOnly)) {
        QByteArray RandomArray = fRandom.read(16);
        RandomArray = RandomArray.toHex().toUpper();
        qDebug("RandomArray : %s", RandomArray.constData());

#if 0
        char buffer[16];
        memset(buffer,0x00,sizeof(buffer));
        qint64 length = fRandom.read(buffer,sizeof(buffer));
        if (length == sizeof(buffer)) {
            qDebug("[AppManager] vehicleid from urandom(bin data):0x%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
                buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6],buffer[7],buffer[8],buffer[9],buffer[10],buffer[11],buffer[12],buffer[13],buffer[14],buffer[15]);
            QString hexString = QString("%1%2").arg(*reinterpret_cast<qulonglong*>(buffer+8), 16, 16,QLatin1Char('0')).toUpper()
                                                .arg(*reinterpret_cast<qulonglong*>(buffer), 16, 16,QLatin1Char('0')).toUpper();
            qDebug("[AppManager] vehicleid string:%s",hexString.toLatin1().constData());
            //APPMGR_WRITE_NVMDATA(this, APNNVM_ID_MDL_VEHICE_ID, hexString.toLatin1().constData(), hexString.toLatin1().length(), result)
        }
        else{
            qDebug("[AppManager] vehicleid get error - file read error");
        }
#endif

        fRandom.close();
    }
    else{
        qDebug("[AppManager] vehicleid get error - file open error");
    }
}

