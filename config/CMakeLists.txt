kcoreaddons_add_plugin(kcm_zephyr SOURCES kcm_breezeenhanced.cpp INSTALL_NAMESPACE "${KDECORATION_KCM_PLUGIN_DIR}")
target_include_directories(kcm_zephyr PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR}/)
target_link_libraries(kcm_zephyr breezeenhancedcommon6 breezeenhanced_STATIC KF6::I18n KF6::KCMUtils Qt::DBus)
kcmutils_generate_desktop_file(kcm_zephyr)
