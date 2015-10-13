Pod::Spec.new do |s|
  s.name         = "SimpleKit"
  s.version      = "1.0"
  s.summary      = "SimpleKit"
  s.homepage     = "https://github.com/b956536180"
  s.license      = "MIT"
  s.author             = { "Xiao" => "956536180@qq.com" }
  s.source       = { :git => "https://github.com/b956536180/SimpleKit.git", :tag => "1.0" }
  s.source_files      = 'SimpleKit.framework/Versions/A/Headers/*.{h}'
  s.exclude_files = "Classes/Exclude"
  s.resources         = 'SimpleKit.bundle'
  s.preserve_paths    = 'SimpleKit.framework/*', 'SimpleKit.bundle'
  s.frameworks        = 'UIKit','QuartzCore', 'Foundation', 'CoreFoundation', 'CoreGraphics','SimpleKit'
  s.xcconfig          =  { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/SimpleKit/"','OTHER_LDFLAGS' => '-lObjC','OTHER_LDFLAGS' => '-all_load' }	
  s.requires_arc      = true
end
