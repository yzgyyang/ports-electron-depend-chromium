--- content/app/content_main_runner.cc.orig	2017-06-05 19:03:06 UTC
+++ content/app/content_main_runner.cc
@@ -86,10 +86,10 @@
 #include "base/posix/global_descriptors.h"
 #include "content/public/common/content_descriptors.h"
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/common/zygote_fork_delegate_linux.h"
 #endif
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include "content/zygote/zygote_main.h"
 #endif
 
@@ -312,7 +312,7 @@ struct MainFunction {
   int (*function)(const MainFunctionParams&);
 };
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 // On platforms that use the zygote, we have a special subset of
 // subprocesses that are launched via the zygote.  This function
 // fills in some process-launching bits around ZygoteMain().
@@ -373,7 +373,7 @@ int RunZygote(const MainFunctionParams& main_function_
   NOTREACHED() << "Unknown zygote process type: " << process_type;
   return 1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 static void RegisterMainThreadFactories() {
 #if !defined(CHROME_MULTIPLE_DLL_BROWSER) && !defined(CHROME_MULTIPLE_DLL_CHILD)
@@ -439,7 +439,7 @@ int RunNamedProcessTypeMain(
     }
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // Zygote startup is special -- see RunZygote comments above
   // for why we don't use ZygoteMain directly.
   if (process_type == switches::kZygoteProcess)
