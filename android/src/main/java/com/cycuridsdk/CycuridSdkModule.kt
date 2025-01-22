package com.cycuridsdk


import android.app.Activity
import android.content.Intent
import android.os.Environment
import com.facebook.react.bridge.*
import com.facebook.react.module.annotations.ReactModule
import java.util.*
import com.cycuridapp.CycurIDClass
import com.cycuridapp.CycurIDConfiguration.Configure
import com.cycuridapp.CycuridType
import com.cycuridapp.Constants
import android.util.Log
import org.json.JSONObject

@ReactModule(name = CycuridSdkModule.NAME)
class CycuridSdkModule(reactContext: ReactApplicationContext) :
  NativeCycuridSdkSpec(reactContext) {

    private var cyruridResultPromise: Promise? = null

    private val activityEventListener = object : BaseActivityEventListener() {
        override fun onActivityResult(
            activity: Activity?,
            requestCode: Int,
            resultCode: Int,
            data: Intent?
        ) {
          if (requestCode == Constants.CYCURID_REQUEST_CODE) {
              val res = data!!.getStringExtra("CYCURID_RESULT")
              if (cyruridResultPromise != null) {
                    if (resultCode == Activity.RESULT_OK && data != null) {
                        val result = data.getStringExtra("CYCURID_RESULT")
                        cyruridResultPromise?.resolve(result)
                    } else {
                        cyruridResultPromise?.reject("CANCELED", "Process was canceled or failed.")
                    }
                    cyruridResultPromise = null
              }
          }
        }
    }

    init {
      reactContext.addActivityEventListener(activityEventListener)
    }


  override fun getName(): String {
    return NAME
  }

  override fun initCycurid(type: String, options: String, promise: Promise) {
    val activity = reactApplicationContext.currentActivity
    cyruridResultPromise = promise
    val jsonObj = JSONObject(options)
    val apiKey = jsonObj.getString("apiKey")
    val secretKey = jsonObj.getString("secretKey")
    val userId = jsonObj.getString("userId")
    // Log.i("TESTANDROID", "Config values ${apiKey} ${secretKey} ${userId}")
    var flowType = CycuridType.isHuman

    when (type) {
        "isHuman" -> flowType = CycuridType.isHuman
        "onboarding" -> flowType = CycuridType.onboarding
        "verification" -> flowType = CycuridType.verification
        "identification" -> flowType = CycuridType.identification
        "dataExtraction" -> flowType = CycuridType.dataExtraction
        else -> { 
            flowType = CycuridType.isHuman
        }
    }
    Configure(activity!!, apiKey, secretKey,userId
        ) { cycurid: CycurIDClass?, error: Error? ->
            if (cycurid != null) {
                cycurid.beginProcess(flowType) 
            } else {
                cyruridResultPromise?.reject("CONFIG_ERROR", error?.message ?: "Unknown error during configuration.")
                cyruridResultPromise = null
                Log.i("Error", "\${error}") 
            }
        }
  }

  companion object {
    const val NAME = "CycuridSdk"
  }
}
