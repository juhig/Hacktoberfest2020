func getAppVersionAsString () -> String {
    let appVersionString = Bundle.main.object(forInfoDictionaryKey: "CFBundleShortVersionString") as! String
    return appVersionString
}

func getAppBuildNumberAsString() -> String {
    let appBuildNumber: String = Bundle.main.object(forInfoDictionaryKey: "CFBundleVersion") as! String
    return appBuildNumber
}

getAppVersionAsString()
getAppBuildNumberAsString()
