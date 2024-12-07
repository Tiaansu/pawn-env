use log::info;
use samp::plugin::SampPlugin;

pub struct PawnEnv;

impl SampPlugin for PawnEnv {
    fn on_load(&mut self) {
        info!("plugin loaded");
    }

    fn on_unload(&mut self) {
        info!("plugin unloaded");
    }
}
